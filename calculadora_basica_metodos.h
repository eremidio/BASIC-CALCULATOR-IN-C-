//Neste arquivo vamos definir os métodos da classe
/*Cabeçalho*/ 
#include"calculadora_basica.h"
#include<gtkmm.h>
#include<iostream>
#include<cmath>
#include<string>
#include<sstream>
using namespace std;
using namespace Glib;
using namespace Gtk;

//Destruidor da classe
calculator::~calculator(){
};

//Construtor da classe
calculator::calculator():base(ORIENTATION_VERTICAL, 5), caixa1(ORIENTATION_VERTICAL, 5), caixa2(ORIENTATION_HORIZONTAL, 5),  zero("0"), um("1"), dois("2"), tres("3"), quatro("4"), cinco("5"), seis("6"), sete("7"), oito("8"), nove("9"), mais("+"), menos("-"), vezes("x"), dividir("/"), igual("="), mais_ou_menos("+/-"), ponto("."), limpar("CE"), desligar("OFF"), memoria("M+"), memoria_cache("MC"), raiz_quadrada("√"), zerozero("00"), backspace("<-")
{
//Definindo o layout do applicativo
set_title("Calculadora básica");
add(base);
base.pack_start(caixa1);
base.pack_start(caixa2);

//Configurando a barra de menu de ajuda
caixa1.pack_start(help_bar, PACK_SHRINK);
auto help=make_managed<MenuItem>("_Ajuda", true);
help->signal_activate().connect(sigc::mem_fun(*this, &calculator::help));
help_bar.append(*help);
help_bar.accelerate(*this);
help_bar.show_all();
//Opções do display
caixa1.pack_start(display, PACK_EXPAND_WIDGET, 5);
display.set_visible(true);
display.set_visibility(true);
display.set_editable(true);
//Ajustando o teclado númerico
caixa2.pack_start(numeric_frame, PACK_EXPAND_WIDGET, 5);
numeric_frame.add(numeric_grid);
numeric_grid.set_row_homogeneous(true);
numeric_grid.set_column_homogeneous(true);
numeric_grid.attach(sete, 0, 0, 1, 1);
numeric_grid.attach(oito, 1, 0, 1, 1);
numeric_grid.attach(nove, 2, 0, 1, 1);
numeric_grid.attach(quatro, 0, 1, 1, 1);
numeric_grid.attach(cinco, 1, 1, 1, 1);
numeric_grid.attach(seis, 2, 1, 1, 1);
numeric_grid.attach(um, 0, 2, 1, 1);
numeric_grid.attach(dois, 1, 2, 1, 1);
numeric_grid.attach(tres, 2, 2, 1, 1);
numeric_grid.attach(zero, 0, 3, 1, 1);
numeric_grid.attach(ponto, 1, 3, 1, 1);
numeric_grid.attach(zerozero, 2, 3, 1, 1);
//Ajustando o teclado de operadores
caixa2.pack_start(arithmetic_frame, PACK_EXPAND_WIDGET, 5);
arithmetic_frame.add(arithmetic_grid);
arithmetic_grid.set_row_homogeneous(true);
arithmetic_grid.set_column_homogeneous(true);
arithmetic_grid.attach(mais, 0, 0, 1, 1);
arithmetic_grid.attach(menos, 0, 1, 1, 1);
arithmetic_grid.attach(vezes, 0, 2, 1, 1);
arithmetic_grid.attach(dividir, 0, 3, 1, 1);
arithmetic_grid.attach(memoria, 1, 0, 1, 1);
arithmetic_grid.attach(memoria_cache, 1, 1, 1, 1);
arithmetic_grid.attach(mais_ou_menos, 1, 2, 1, 1);
arithmetic_grid.attach(raiz_quadrada, 1, 3, 1, 1);
arithmetic_grid.attach(limpar, 2, 0, 1, 1);
arithmetic_grid.attach(desligar, 2, 1, 1, 1);
arithmetic_grid.attach(backspace, 2, 2, 1, 1);
arithmetic_grid.attach(igual, 2, 3, 1, 1);
//Linkando as funções aos botões
//Funções de uso geral
limpar.signal_clicked().connect(sigc::mem_fun(*this, &calculator::ce));
desligar.signal_clicked().connect(sigc::mem_fun(*this, &calculator::off));
mais_ou_menos.signal_clicked().connect(sigc::mem_fun(*this, &calculator::plus_minus));
igual.signal_clicked().connect(sigc::mem_fun(*this, &calculator::equal));
memoria.signal_clicked().connect(sigc::mem_fun(*this, &calculator::memory));
memoria_cache.signal_clicked().connect(sigc::mem_fun(*this, &calculator::memory_clear));
backspace.signal_clicked().connect(sigc::mem_fun(*this, &calculator::back));
//Funções de entradas de dados
zerozero.signal_clicked().connect(sigc::mem_fun(*this, &calculator::put_00));
zero.signal_clicked().connect(sigc::mem_fun(*this, &calculator::put_0));
um.signal_clicked().connect(sigc::mem_fun(*this, &calculator::put_1));
dois.signal_clicked().connect(sigc::mem_fun(*this, &calculator::put_2));
tres.signal_clicked().connect(sigc::mem_fun(*this, &calculator::put_3));
quatro.signal_clicked().connect(sigc::mem_fun(*this, &calculator::put_4));
cinco.signal_clicked().connect(sigc::mem_fun(*this, &calculator::put_5));
seis.signal_clicked().connect(sigc::mem_fun(*this, &calculator::put_6));
sete.signal_clicked().connect(sigc::mem_fun(*this, &calculator::put_7));
oito.signal_clicked().connect(sigc::mem_fun(*this, &calculator::put_8));
nove.signal_clicked().connect(sigc::mem_fun(*this, &calculator::put_9));
ponto.signal_clicked().connect(sigc::mem_fun(*this, &calculator::put_point));
//Funções de operadores matemáticos
raiz_quadrada.signal_clicked().connect(sigc::mem_fun(*this, &calculator::square_root));
mais.signal_clicked().connect(sigc::mem_fun(*this, &calculator::add2));
menos.signal_clicked().connect(sigc::mem_fun(*this, &calculator::subtract));
vezes.signal_clicked().connect(sigc::mem_fun(*this, &calculator::multiply));
dividir.signal_clicked().connect(sigc::mem_fun(*this, &calculator::divide));

//Exibindo widgets do app
show_all_children();
};

//Métodos da classe
//Funções de uso geral
void calculator::off(){
exit(0);
};

void calculator::ce(){
parcela1=0.0;
parcela2=0.0;
resultado=0.0;
memoria_valor=0.0;
display_valor=0.0;
display.set_text("");
};

void calculator::plus_minus(){
display_texto=display.get_text();
stringstream(display_texto)>>display_valor;
temp=display_valor*(-1.0);
display.set_text(to_string(temp));
};

void calculator::memory(){
display_texto=display.get_text();
stringstream(display_texto)>>memoria_valor;
display.set_text("");
};

void calculator::memory_clear(){
display.set_text(to_string(memoria_valor));
memoria_valor=0.0;
};


void calculator::back(){
display_texto=display.get_text();
display_texto.pop_back();
display.set_text(display_texto);
};

//Funções de inserção de texto
void calculator::put_point(){
char c='.';
display_texto=display.get_text();
display_texto.push_back(c);
display.set_text(display_texto);
};

void calculator::put_0(){
char c='0';
display_texto=display.get_text();
display_texto.push_back(c);
display.set_text(display_texto);
};

void calculator::put_00(){
string c="00";
display_texto=display.get_text();
display_texto+=c;
display.set_text(display_texto);
};

void calculator::put_1(){
char c='1';
display_texto=display.get_text();
display_texto.push_back(c);
display.set_text(display_texto);
};

void calculator::put_2(){
char c='2';
display_texto=display.get_text();
display_texto.push_back(c);
display.set_text(display_texto);
};

void calculator::put_3(){
char c='3';
display_texto=display.get_text();
display_texto.push_back(c);
display.set_text(display_texto);
};

void calculator::put_4(){
char c='4';
display_texto=display.get_text();
display_texto.push_back(c);
display.set_text(display_texto);
};

void calculator::put_5(){
char c='5';
display_texto=display.get_text();
display_texto.push_back(c);
display.set_text(display_texto);
};

void calculator::put_6(){
char c='6';
display_texto=display.get_text();
display_texto.push_back(c);
display.set_text(display_texto);
};

void calculator::put_7(){
char c='7';
display_texto=display.get_text();
display_texto.push_back(c);
display.set_text(display_texto);
};

void calculator::put_8(){
char c='8';
display_texto=display.get_text();
display_texto.push_back(c);
display.set_text(display_texto);
};

void calculator::put_9(){
char c='9';
display_texto=display.get_text();
display_texto.push_back(c);
display.set_text(display_texto);
};

//Funções de operadores matemáticos

void calculator::add2(){
ad=true;
su=false;
mu=false;
di=false;
display_texto=display.get_text();
stringstream(display_texto)>>parcela1;
display.set_text("");
};

void calculator::subtract(){
ad=false;
su=true;
mu=false;
di=false;
display_texto=display.get_text();
stringstream(display_texto)>>parcela1;
display.set_text("");
};

void calculator::multiply(){
ad=false;
su=false;
mu=true;
di=false;
display_texto=display.get_text();
stringstream(display_texto)>>parcela1;
display.set_text("");
};

void calculator::divide(){
ad=false;
su=false;
mu=false;
di=true;
display_texto=display.get_text();
stringstream(display_texto)>>parcela1;
display.set_text("");
};

void calculator::equal(){
display_texto=display.get_text();
stringstream(display_texto)>>parcela2;
if(ad==true && su==false && mu==false && di==false)
resultado=parcela1+parcela2;
if(ad==false && su==true && mu==false && di==false)
resultado=parcela1-parcela2;
if(ad==false && su==false && mu==true && di==false)
resultado=parcela1*parcela2;
if(ad==false && su==false && mu==false && di==true)
resultado=parcela1/parcela2;
display.set_text(to_string(resultado));
};

void calculator::square_root(){
display_texto=display.get_text();
stringstream(display_texto)>>parcela1;
resultado=sqrt(parcela1);
display.set_text(to_string(resultado));
};

//Função de ajuda
void calculator::help(){
help_window->set_default_size(600, 600);
help_window->show();
help_window->show_all_children();
help_window->set_title("Calculadora básica - ajuda.");
}

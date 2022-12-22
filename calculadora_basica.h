//Este arquivo contém a classe do app da calculadora
/*Cabecalho*/
#include<gtkmm.h>
#include"calculadora_basica_ajuda.h"
using namespace std;
using namespace Glib;
using namespace Gtk;


//CLASSE DO APP

class calculator: public Window{
public:
//Construtor e destruidor da classe
calculator();
virtual ~calculator();
//Membros usados como variáveis
string display_texto, display_temp;
long double parcela1, parcela2, resultado, memoria_valor, display_valor, temp;
bool ad, su, mu, di;

//WIDGETS
//CAIXAS
Box base, caixa1, caixa2;
//TELA DA CALCULADORA
Entry display;
//FRAMES E  MALHAS PARA ORGARNIZAR OS BOTÕES
Grid numeric_grid, arithmetic_grid;
Frame numeric_frame, arithmetic_frame;
//BUTTONS
Button zero, zerozero, um, dois, tres, quatro, cinco, seis, sete, oito, nove, mais, menos, vezes, dividir,  mais_ou_menos, ponto;
Button limpar, desligar, memoria, memoria_cache, raiz_quadrada, backspace, igual;
//JANELA DE AJUDA E BARRA DE MENU
MenuBar help_bar;
HelpWindow* help_window=new HelpWindow;
//FUNÇÕES ÚTEIS
void ce();
void off();
void plus_minus();
void back();
void equal();
//FUNÇÕES DE ENTRADAS DE DADOS
void put_point();
void put_00();
void put_0();
void put_1();
void put_2();
void put_3();
void put_4();
void put_5();
void put_6();
void put_7();
void put_8();
void put_9();
//FUNÇÕES DE OPERADDORES MATEMÁTICOS E MANIPULAÇÃO DE VARIÁVEIS
void add2();
void subtract();
void multiply();
void divide();
void memory();
void memory_clear();
void square_root();
//AJUDA
void help();
};

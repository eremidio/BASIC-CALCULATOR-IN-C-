//Este arquivo contém a classe do app da calcculadora
/*Cabecalho*/
#include<gtkmm.h>
using namespace std;
using namespace Glib;
using namespace Gtk;


//Definindo a classe de aplicativos

class calculator: public Window{
public:
//Construtor e destruidor da classe
calculator();
virtual ~calculator();
//Membros usados como variáveis
string display_texto, display_temp;
long double parcela1, parcela2, resultado, memoria_valor, display_valor, temp;
bool ad, su, mu, di;

//Widgets (nomes em português)
//Box
Box base, caixa1, caixa2;
//TELA DA CALCULADORA
Entry display;
//FRAMES E  MALHAS PARA ORGARNIZAR OS BOTÕES
Grid numeric_grid, arithmetic_grid;
Frame numeric_frame, arithmetic_frame;
//BUTTONS
Button zero, um, dois, tres, quatro, cinco, seis, sete, oito, nove, mais, menos, vezes, dividir, igual, mais_ou_menos, ponto;
Button limpar, desligar, memoria, memoria_cache, raiz_quadrada;

//Funções úteis (nomes em inglês)
void ce();
void off();
void plus_minus();
void equal();
void put_point();
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
void add2();
void subtract();
void multiply();
void divide();
void memory();
void memory_clear();
void square_root();

};

/*CABEÇALHO*/
#include<gtkmm.h>
#include<iostream>

using namespace std;
using namespace Glib;
using namespace Gtk;

/*CLASSE DE MENU DE AJUDA LABEL+SCROLLEDWINDOW*/
class HelpWindow: public Window{
public:

//CONSTRUTOR E DESTRUIDOR DA CLASSE
HelpWindow();
virtual ~HelpWindow();
//WIDGETS
ScrolledWindow help_scrolledwindow;
Label help_label;

};

//DESTRUIDOR DA CLASSE
HelpWindow::~HelpWindow(){
};

//CONSTRUTOR DA CLASSE
HelpWindow::HelpWindow(){

//LAYOUT
add(help_scrolledwindow);
help_scrolledwindow.set_policy(POLICY_AUTOMATIC, POLICY_AUTOMATIC);
help_scrolledwindow.add(help_label);
help_label.set_justify(JUSTIFY_LEFT);
//TEXTO DE AJUDA A SER EXIBIDO NA JANELA SECUNDÁRIA
help_label.set_text("CALCULADORA BÁSICA - Versão 2.0\n"
"----------------------------------------------------------------\n\n"
"Este aplicativo permite ao usuário realizar cálculos matemáticos básicos.\n\n"

"1.0 - LAYOUT E FUNCIONALIDADE GERAL DO APLICATIVO\n"
"----------------------------------------------------------------\n\n"
"Este aplicativo dispõe dos seguintes elementos gráficos: um display, no qual as parcelas e os resultados das \noperações matemáticas são inseridos/exibidos; um teclado númerico e um teclado com operadores matemáticos.\n\n"
"2.0 - MENUS \n"
"----------------------------------------------------------------\n\n"
"2.1 - TECLADO NÚMERICO \n"
"----------------------------------------------------------------\n\n"
"Este menu contém botões com os algarismos de 0-9 e o separador de casas decimais '.'.\nAo se pressionar um botão, o respectivo caractére é inserido no display da calculadora.\nA inserção de dados pode ser feita manualmente dando-se um duplo clique no display da calculadora, usando-se o teclado do computador.\n\n"
"2.2 - MENU DE OPERADORES ARITMÉTICOS \n"
"----------------------------------------------------------------\n"
"Este menu contém um conjunto de operadores matemáticos básicos.\n"
"Os botões '+', '-', 'x', '/' ativam os respectivos operadores matemáticos.\nPara acionar estes operadores, o usuário deve inserir a primeira parcela da operação e em\nseguida pressionar o botão associado ao operador correspondente e inserir a segunda parcela da operação,\napós pressionar o botão de confirmação '=' o resultado será exibido no display da calculadora.\n"
"O botão '√' retorna a raiz quadrada de um número.\n"
"O botão '+/-' muda o sinal do argumento exibido no display da calculadora.\n"
"O botão 'CE' remove conteúdo exibido no display e reseta as variáveis usadas nos cálculos para valores padrões.\n"
"O botão 'OFF' encerra o aplicativo da calculadora.\n"
"O botão '<-' remove o último caractére exibido no display da calculadora (da direita para a esquerda).\n"
"O botão 'MR' remove conteúdo exibido no display e aloca seu conteúdo no cachê de memória da calculadora.\n"
"O botão 'MC' esvazia o cachê de memória da calculadora e exibe o conteúdo alocado no display.\n\n"
"3.0 - AGRADECIMENTOS\n"
"----------------------------------------------------------------\n\n"
"Obrigado pela preferência. Sugestões de melhorias entrar em contato com: e.r.emidio@yandex.com.\n\n"

);



};

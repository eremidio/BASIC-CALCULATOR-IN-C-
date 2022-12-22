//Vamos construir uma calclculadora simples em C++
/*Compilar este programa com o comando em plataformas Linux: g++ -o calculadora_basica calculadora_basica.cpp `pkg-config gtkmm-3.0 --cflags --libs` 
*/


/*Cabeçalho*/
#include<gtkmm/application.h>
#include"calculadora_basica_metodos.h"
using namespace std;
using namespace Glib;
using namespace Gtk;

int main(int argc, char* argv[]){
//Ponteiro smart
RefPtr<Application> app=Application::create(argc, argv);
//Instanciando a classe do app
calculator calculadora;
calculadora.set_default_size(450, 400);
//Rodando o app
return app->run(calculadora);
}

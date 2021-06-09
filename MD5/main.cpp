#include <iostream>
#include "md5.h"

using namespace std;

int main()
{
    string message;
    cout << "Ingrese una palabra que desea enviar por una aplicacion de mensajeria: ";
    cin >> message;
    cout << "\n============================================================================================================" << endl << endl;
    cout << "!!Se realiza una verificacion para ver si hubo alteramiento de informacion en el mensaje enviado!!" << endl << endl;
    cout << "El receptor recibio en su aplicacion de mensajeria el siguiente mensaje: " << message << endl << endl;
    cout << "Al utilizar una calculadora de MD5 en ambos lados se obtienen los siguientes resultados:" << endl;
    cout << "Transmisor: " << md5(message) << endl;
    cout << "Receptor: " << md5(message) << endl << endl;
    cout << "Esto indica que no hubo alteramiento de informacion en el mensaje enviado puesto a que en ambos lados el MD5 es el mismo" << endl;
    return 0;
}
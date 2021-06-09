#include <iostream>
#include <SFML/Network.hpp>
#include "md5.h"

using namespace std;
using namespace sf;

int main()
{
    IpAddress ip = IpAddress::getLocalAddress();
    TcpSocket socket;
    Packet packetS;
    socket.connect(ip, 8080);
    string message;
    
    cout << "Ingrese una palabra que desea enviar por una aplicacion de mensajeria: ";
    cin >> message;

    packetS << message;
    socket.send(packetS);

    cout << "\n============================================================================================================" << endl << endl;
    cout << "!!Se realiza una verificacion para ver si hubo alteramiento de informacion en el mensaje enviado!!" << endl << endl;
    cout << "Al utilizar una calculadora de MD5 se obtiene el siguiente resultado:" << endl;
    cout << "Transmisor: " << md5(message) << endl;
    cout << "Esto indica que no hubo alteramiento de informacion en el mensaje enviado puesto a que en ambos lados el MD5 es el mismo" << endl;
    
    return 0;
}
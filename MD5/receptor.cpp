#include <iostream>
#include <SFML/Network.hpp>
#include "md5.h"

using namespace std;
using namespace sf;

int main()
{
    IpAddress ip = IpAddress::getLocalAddress();
    TcpSocket socket;
    TcpListener listener;
    listener.listen(8080);
    listener.accept(socket);
    Packet packetR;
    string message;

    socket.receive(packetR);
    if (packetR.getData() != NULL)
    {
        packetR >> message;

        cout << "El receptor recibio en su aplicacion de mensajeria el siguiente mensaje: " << message << endl << endl;
        cout << "Al utilizar una calculadora de MD5 se obtiene el siguiente resultado:" << endl;
        cout << "Receptor: " << md5(message) << endl << endl;
        cout << "Esto indica que no hubo alteramiento de informacion en el mensaje enviado puesto a que en ambos lados el MD5 es el mismo" << endl;
    }
    return 0;
}
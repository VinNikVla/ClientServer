#include <QCoreApplication>
#include "udpserver.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);


    UDPclient* server = new UDPclient("127.0.0.1", "127.0.0.1", 1111, &a, 1112);

    return a.exec();
}

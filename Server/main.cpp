#include <QCoreApplication>
#include "udpserver.h"
#include "thread"
#include "chrono"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    typedef union {
        int x;
        quint8 ch[4];

    } intToChar;

    UDPclient* server = new UDPclient("127.0.0.1", "127.0.0.1", 1111, &a, 1112);

    QByteArray com;
    com.reserve(5);

    intToChar convert;

    //    qDebug() << "1byte = " << convert.ch[0];
    //    qDebug() << "2byte = " << convert.ch[1];
    //    qDebug() << "3byte = " << convert.ch[2];
    //    qDebug() << "4byte = " << convert.ch[3];
    //    quint8 frst= value & 0x000000ff;
    //    quint8 second = value & 0x0000ff00;
    //    qDebug() << hex << frst << hex << second << hex << value;
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 200;j++)
        {

            com[0] = static_cast<quint8>(i);
            convert.x = j;
            com[1] = convert.ch[3];
            com[2] = convert.ch[2];
            com[3] = convert.ch[1];
            com[4] = convert.ch[0];
            server->sendDataTo(com);
            std::this_thread::sleep_for(std::chrono::milliseconds(50));
        }
    }





    return a.exec();
}

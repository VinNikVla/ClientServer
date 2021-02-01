#include <QApplication>
#include "UDP/udpserver.h"
//#include "udpserver.h"
#include "thread"
#include "chrono"
#include "conditionerserver.h"
#include "gui.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    typedef union {
        int x;
        quint8 ch[4];

    } intToChar;

    UDPclient* server = new UDPclient("127.0.0.1", "127.0.0.1", 1111, &a, 1112);

    GUI gui;

    QByteArray com;
    com.reserve(5);

    ConditionerServer* conditioner = new ConditionerServer(server, &a);

    for(auto itb = ControlTypes::command.begin(), ite = ControlTypes::command.end(); itb != ite; ++itb)
    {   if(*itb != ControlTypes::Conditioner::OnOff)
        {
            QObject::connect(gui.getControl(*itb), &Control::valueChanged, conditioner->getDetector(*itb), &ValueModel::signalValueToClient);
        }

    }


    gui.show();



    return a.exec();
}

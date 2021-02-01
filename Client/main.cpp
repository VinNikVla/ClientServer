#include "widget.h"
#include "settings.h"
#include "conditioner.h"
//#include "udpclient.h"
#include "UDP/udpclient.h"
#include "temperature.h"
#include "pressure.h"

#include <QApplication>
#include <QDesktopWidget>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Settings* set = new Settings(&a);

        Widget w;

    UDPCLient* client = new UDPCLient("127.0.0.1", 1111, &a);



    QDesktopWidget* p_desktop = QApplication::desktop();
    const QRect sizeDesktop = p_desktop->screenGeometry();
    w.setGeometry(sizeDesktop.width() / 4, sizeDesktop.height() / 4,sizeDesktop.width() / 2 ,sizeDesktop.height() / 2);

    Conditioner* conditioner = new Conditioner(set, "127.0.0.1", 1111, &a);

    //!!!!!!!!!!Нужно сделать единый класс для View и Control!!!!!!!!!!
    //нужно сделать манагер
    //нужно сделать области
    //нужно обработать запись в файл
    //

    for(auto itb = ControlTypes::command.begin(), ite = ControlTypes::command.end(); itb != ite; ++itb)
    {
        QObject::connect(w.getView(*itb), &View::signalChangeTypeMeasurements, conditioner->getDetector(*itb), &ValueModel::slotChangeTypeValue);
        QObject::connect(conditioner->getDetector(*itb), &ValueModel::signalValueChanged, w.getView(*itb), &View::slotChangeValue);
    }

    QObject::connect(conditioner->getDetector(ControlTypes::Conditioner::OnOff), &ValueModel::signalServerConnected, &w, &Widget::slotEnabledControl);

    QObject::connect(conditioner, &Conditioner::sendCommandToServer, client, &UDPCLient::sendDataTo);
    QObject::connect(client,&UDPCLient::receiveData, conditioner, &Conditioner::responseFromServer);

    QObject::connect(w.getControl(ControlTypes::Conditioner::Temperature), &Control::valueChanged, conditioner, &Conditioner::sendCommand);

    QObject::connect(conditioner, &Conditioner::signalChangeComlexState, w.getState(), &CircleState::changeState);
    w.show();

    return a.exec();
}

#include "widget.h"
#include "settings.h"
#include "conditioner.h"
#include "udpclient.h"
#include "temperature.h"
#include "pressure.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Settings* set = new Settings(&a);

        Widget w;

    UDPCLient* client = new UDPCLient("127.0.0.1", 1111, &a);



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

    QObject::connect(conditioner, &Conditioner::sendCommandToServer, client, &UDPCLient::sendDataTo);
    QObject::connect(client,&UDPCLient::receiveData, conditioner, &Conditioner::responseFromServer);

    QObject::connect(w.getControl("ControlTemperature"), &Control::valueChanged, conditioner, &Conditioner::sendCommand);


    w.show();

    return a.exec();
}

#include "widget.h"
#include "settings.h"
#include "conditioner.h"
#include "udpclient.h"
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

    QObject::connect(conditioner, &Conditioner::sendCommandToServer, client, &UDPCLient::sendDataTo);
    QObject::connect(client,&UDPCLient::receiveData, conditioner, &Conditioner::responseFromServer);

    QObject::connect(w.getView("ViewTemperature"), &View::signalChangeTypeMeasurements, conditioner, &Conditioner::slotChangeTypeTemperature);
    QObject::connect(conditioner, &Conditioner::signalTemperatureChanged, w.getView("ViewTemperature"), &View::slotChangeValue);

    QObject::connect(w.getView("ViewPressure"), &View::signalChangeTypeMeasurements, conditioner, &Conditioner::slotChangeTypePressure);
    QObject::connect(conditioner, &Conditioner::signalPressureChanged, w.getView("ViewPressure"), &View::slotChangeValue);

    QObject::connect(w.getView("ViewHumadity"), &View::signalChangeTypeMeasurements, conditioner, &Conditioner::slotChangeTypeHumadity);
    QObject::connect(conditioner, &Conditioner::signalHumadityChanged, w.getView("ViewHumadity"), &View::slotChangeValue);

    QObject::connect(w.getControl("ControlTemperature"), &Control::valueChanged, conditioner, &Conditioner::sendCommand);




    conditioner->slotChangeTypeHumadity("%");
    w.show();

    return a.exec();
}

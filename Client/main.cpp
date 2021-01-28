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


    QObject::connect(w.getView("ViewTemperature"), &View::signalChangeTypeMeasurements, conditioner, &Conditioner::slotChangeTypeTemperature);
    QObject::connect(conditioner, &Conditioner::signalTemperatureChanged, w.getView("ViewTemperature"), &View::slotChangeValue);

    QObject::connect(w.getView("ViewPressure"), &View::signalChangeTypeMeasurements, conditioner, &Conditioner::slotChangeTypePressure);
    QObject::connect(conditioner, &Conditioner::signalPressureChanged, w.getView("ViewPressure"), &View::slotChangeValue);

    QObject::connect(w.getControl("ControlTemperature"), &Control::valueChanged, conditioner, &Conditioner::sendCommand);


    QObject::connect(conditioner, &Conditioner::sendCommandToServer, client, &UDPCLient::sendDataTo);

    w.show();

    return a.exec();
}

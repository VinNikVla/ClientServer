#include "widget.h"
#include "settings.h"
#include "conditioner.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Settings* set = new Settings(&a);

    Conditioner* conditioner = new Conditioner(set, "192.168.3.3", 1111, &a);

    Widget w;

    QObject::connect(w.getView("ViewTemperature"), &View::signalChangeTypeMeasurements, conditioner, &Conditioner::changeTypeMeasurementsTemperature);
    QObject::connect(conditioner, &Conditioner::signalTemperatureChanged, w.getView("ViewTemperature"), &View::slotChangeValue);

    QObject::connect(w.getView("ViewPressure"), &View::signalChangeTypeMeasurements, conditioner, &Conditioner::changeTypePressure);
    QObject::connect(conditioner, &Conditioner::signalPressureChanged, w.getView("ViewPressure"), &View::slotChangeValue);


    w.show();

    return a.exec();
}

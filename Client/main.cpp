#include "widget.h"
#include "settings.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Settings* set = new Settings(&a);

    set->setTypeTemperature(Settings::TypeDisplayTemperature::Kelvin);

    Widget w;
    w.show();

    return a.exec();
}

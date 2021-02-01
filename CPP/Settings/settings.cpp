#include "settings.h"

Settings::Settings(QObject *parent):
    QObject(parent),
    set(new QSettings(QSettings::IniFormat, QSettings::UserScope, "/settingClient"))
{
    qDebug() << set->fileName();
    readMe();
    writeMe();

}

Settings::~Settings()
{
    writeMe();
}

QString Settings::getTypePressure() const
{
    return typePressure;
}

void Settings::setTypePressure(const QString& pressure)
{
    if(pressure == typePressure)
        return;

    typePressure = pressure;
}

void Settings::setTypeTemperature(const QString& temperature)
{
    if(temperature == typeTemperature)
        return;

    typeTemperature = temperature;
}


QString Settings::getTypeTemperature() const
{
    return typeTemperature;
}



void Settings::readMe()
{
    typePressure = set->value("TypePressure", "мм.рт.ст").toString();
    typeTemperature = set->value("TypeTemperature", "°C").toString();
}

void Settings::writeMe()
{
    qDebug() << typeTemperature << " " << typePressure;
    set->setValue("TypePressure", typePressure);
    set->setValue("TypeTemperature", typeTemperature);
    set->sync();
}

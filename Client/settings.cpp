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

void Settings::setTypeHumadity(const QString &humadity)
{
    if(humadity == typeHumadity)
        return;

    typeHumadity = humadity;
}

QString Settings::getTypeTemperature() const
{
    return typeTemperature;
}

QString Settings::getTypeHumadity() const
{
    return typeHumadity;
}

void Settings::readMe()
{
    typePressure = set->value("TypePressure", "мм.рт.ст").toString();
    typeTemperature = set->value("TypeTemperature", "°C").toString();
    typeHumadity = set->value("TypeHumadity", "%").toString();

}

void Settings::writeMe()
{
    qDebug() << typeTemperature << " " << typePressure << " " << typeHumadity;
    set->setValue("TypePressure", typePressure);
    set->setValue("TypeTemperature", typeTemperature);
    set->setValue("TypeHumadity", typeHumadity);
    set->sync();
}

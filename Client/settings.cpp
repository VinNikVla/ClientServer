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

ControlTypes::TypeDisplayPressure Settings::getTypePressure() const
{
    return typePressure;
}

void Settings::setTypePressure(const ControlTypes::TypeDisplayPressure &pressure)
{
    if(pressure == typePressure)
        return;

    typePressure = pressure;
}

void Settings::setTypeTemperature(const ControlTypes::TypeDisplayTemperature &temperature)
{
    if(temperature == typeTemperature)
        return;

    typeTemperature = temperature;
}

ControlTypes::TypeDisplayTemperature Settings::getTypeTemperature() const
{
    return typeTemperature;
}

void Settings::readMe()
{
    typePressure = static_cast<ControlTypes::TypeDisplayPressure>(set->value("TypeTemperature").toUInt());
    typeTemperature = static_cast<ControlTypes::TypeDisplayTemperature>(set->value("TypePressure").toBool());

}

void Settings::writeMe()
{
    qDebug() << static_cast<unsigned int>(typeTemperature);
    set->setValue("TypePressure", static_cast<bool>(typePressure));
    set->setValue("TypeTemperature", static_cast<unsigned int>(typeTemperature));
    set->sync();
}

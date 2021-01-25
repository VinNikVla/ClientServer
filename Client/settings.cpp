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

void Settings::setTypePressure(const Settings::TypeDisplayPressure &pressure)
{
    if(pressure == typePressure)
        return;

    typePressure = pressure;
}

void Settings::setTypeTemperature(const Settings::TypeDisplayTemperature &temperature)
{
    if(temperature == typeTemperature)
        return;

    typeTemperature = temperature;
}

void Settings::readMe()
{
    typePressure = static_cast<TypeDisplayPressure>(set->value("TypeTemperature").toUInt());
    typeTemperature = static_cast<TypeDisplayTemperature>(set->value("TypePressure").toBool());

}

void Settings::writeMe()
{
    qDebug() << static_cast<unsigned int>(typeTemperature);
    set->setValue("TypePressure", static_cast<bool>(typePressure));
    set->setValue("TypeTemperature", static_cast<unsigned int>(typeTemperature));
    set->sync();
}

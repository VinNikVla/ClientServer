#ifndef SETTINGS_H
#define SETTINGS_H

#include <QObject>
#include <QSettings>
#include <QDebug>
#include <QVariant>
#include "global.h"



class Settings: public QObject
{
    Q_OBJECT
public:
    Settings(QObject * parent = nullptr);
    ~Settings();

    ControlTypes::TypeDisplayPressure getTypePressure() const;
    ControlTypes::TypeDisplayTemperature getTypeTemperature() const;

    void setTypePressure(const ControlTypes::TypeDisplayPressure& pressure);
    void setTypeTemperature(const ControlTypes::TypeDisplayTemperature& temperature);


private:
    ControlTypes::TypeDisplayTemperature typeTemperature;
    ControlTypes::TypeDisplayPressure typePressure;
    QSettings* set = nullptr;

    void readMe();
    void writeMe();
};

#endif // SETTINGS_H

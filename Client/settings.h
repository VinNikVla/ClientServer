#ifndef SETTINGS_H
#define SETTINGS_H

#include <QObject>
#include <QSettings>
#include <QDebug>
#include <QVariant>



class Settings: public QObject
{
    Q_OBJECT
public:
    Settings(QObject * parent = nullptr);
    ~Settings();

    enum class TypeDisplayTemperature: quint16
    {
        Celsius,
        Kelvin,
        Fahrenheit
    };

    enum class TypeDisplayPressure: bool
    {
        Pascal,
        MillimetersOfMercury
    };



    TypeDisplayPressure getTypePressure() const;
    TypeDisplayTemperature getTypeTemperature() const;

    void setTypePressure(const TypeDisplayPressure& pressure);
    void setTypeTemperature(const TypeDisplayTemperature& temperature);
private:
    TypeDisplayTemperature typeTemperature;
    TypeDisplayPressure typePressure;
    QSettings* set = nullptr;

    void readMe();
    void writeMe();
};

#endif // SETTINGS_H

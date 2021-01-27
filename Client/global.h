#ifndef GLOBAL_H
#define GLOBAL_H

#include <QString>
#include <QVector>

namespace ControlTypes {
enum class TypeControl:quint8
{
    HorizontalSlider,
    VerticalSlider,
    Button,
    SpinBox,
    Dial
};

enum class Conditioner: quint8
{
    Temperature,
    Humadity,
    Pressure
};

enum class TypeDisplayTemperature: quint16
{
    Celsius,
    Kelvin,
    Fahrenheit
};

ControlTypes::TypeDisplayTemperature toTypeDisplayTemperature(const QString& type);

enum class TypeDisplayPressure: bool
{
    Pascal,
    MillimetersOfMercury
};


const QVector<QString> stringTypeTemperature = { "°C", "°F", "K"};
const QVector<QString> stringTypePressure = {"мм.рт.ст", "Па"};

}
#endif // GLOBAL_H

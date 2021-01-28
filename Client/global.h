#ifndef GLOBAL_H
#define GLOBAL_H

#include <QString>
#include <QVector>
#include <QDebug>

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
    Pressure,
    OnOff,
    Direction
};

const QVector<QString> stringTypeTemperature = { "°C", "°F", "K"};
const QVector<QString> stringTypePressure = {"мм.рт.ст", "Па"};
const QVector<QString> stringTypeHumadity = {"%"};
}


QDebug operator << (QDebug debug, const ControlTypes::Conditioner &state);

#endif // GLOBAL_H

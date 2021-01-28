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
    Direction,
    Request
};

enum class TypeElement:quint8
{
    View,
    Control
};



const QVector<QString> stringTypeTemperature = { "°C", "°F", "K"};
const QVector<QString> stringTypePressure = {"мм.рт.ст", "Па"};
const QVector<QString> stringTypeHumadity = {"%"};
}


QDebug operator << (QDebug debug, const ControlTypes::Conditioner &state);
//QString toString(const  ControlTypes::Conditioner)
//{


enum class DeviceState: quint8 {
    Green,      ///< Зеленый - значит все отлично
    Yellow,     ///< Желтый - есть небольшие проблемы, но работоспособность не утрачена
    Red,        ///< Красный - все плохо!! Обрати на меня внимание!
    Unknown     ///< Состояние не определено. Блок еще не опрошен, или внешняя система (внешние системы диагностике не подлежат).
};

#endif // GLOBAL_H

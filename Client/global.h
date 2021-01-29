#ifndef GLOBAL_H
#define GLOBAL_H

#include <QString>
#include <QVector>
#include <QDebug>
#include <QMap>
#include <QPair>

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
    RequestParameters,
    CheckConnections
};

const QVector<Conditioner> command = { Conditioner::Temperature,
                                       Conditioner::Humadity,
                                       Conditioner::Pressure/*,
                                       Conditioner::OnOff,
                                       Conditioner::Direction,
                                       Conditioner::RequestParameters,
                                       Conditioner::CheckConnections*/
                                     };

enum class TypeElement:quint8
{
    View,
    Control
};

//QMap<Conditioner, QPair<const QVector<QString>*, const QVector<int>*>> mapDetector;



const QVector<QString> stringTypeTemperature = { "°C", "°F", "K"};
const QVector<int> stateTemperature = { 60, 100, 40, 59};
const QVector<QString> stringTypePressure = {"мм.рт.ст", "Па"};
const QVector<int> statePressure = { 60, 100, 40, 59};
const QVector<QString> stringTypeHumadity = {"%"};
const QVector<int> stateHumadity = { 650, 720, 40, 59};
//const QVecotr<int> stateHumadity = {
}


QDebug operator << (QDebug debug, const ControlTypes::Conditioner &state);


QString toString(const ControlTypes::Conditioner &state);




enum class DeviceState: quint8 {
    Green,      ///< Зеленый - значит все отлично
    Yellow,     ///< Желтый - есть небольшие проблемы, но работоспособность не утрачена
    Red,        ///< Красный - все плохо!! Обрати на меня внимание!
    Unknown     ///< Состояние не определено. Блок еще не опрошен, или внешняя система (внешние системы диагностике не подлежат).
};

#endif // GLOBAL_H

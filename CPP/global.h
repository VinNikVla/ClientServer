#ifndef GLOBAL_H
#define GLOBAL_H

#include <QString>
#include <QVector>
#include <QDebug>
#include <QMap>
#include <QPair>
//#include <typ

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
    CheckConnections,
    ComplexState
};

const QVector<int> stateTemperature = { 20, 30, 10, 19};
const QPair<int, int> borderTemperature = {5,30};

const QVector<QPair<QString, QPair<double, double>>> measurmentsTemperature = { {"°C", {1,0}},
                                                                                {"°F", {1.8,32}},
                                                                                {"K",  {1, 273.15}}
                                                                              };

const QVector<int> statePressure = { 600, 720, 500, 780};
const QPair<int, int> borderPressure = {0, 800};

const QVector<QPair<QString, QPair<double, double>>> measurmentsPressure = { {"мм.рт.ст", {1,0}},
                                                                             {"Па", {133.3223684,0}}
                                                                           };

const QVector<int> stateHumadity = { 60, 100, 40, 59};
const QPair<int, int> borderHumadity = {0, 100};

const QVector<QPair<QString, QPair<double, double>>> measurmentsHumadity = { {"%", {1,0}}};

const QPair<int, int> borderDirection = {10, 90};
const QVector<int> stateDirection{10, 90, 10, 90};

const QVector<QPair<QString, QPair<double, double>>> measurmentsDirection = { {"°", {1,0}}};


const QVector<QString> stringTypeServer = { "Включить", "Выключить"};
const QVector<int> stateServer = {1,1,1,1};

enum class Server: int
{
    OFF,
    ON
};

const QVector<Conditioner> command = { Conditioner::Temperature,
                                       Conditioner::Humadity,
                                       Conditioner::Pressure,
                                       Conditioner::OnOff,
                                       Conditioner::Direction,
                                       Conditioner::RequestParameters,
                                       //                                       Conditioner::CheckConnections
                                     };

const QVector<Conditioner> _server = {
                                           Conditioner::Temperature,
                                           Conditioner::Humadity,
                                           Conditioner::Pressure,
                                           Conditioner::OnOff,
                                           Conditioner::Direction
};



const QVector<Conditioner> control = {  Conditioner::Temperature,
                                        Conditioner::OnOff,
                                        Conditioner::Direction

                                     };

const QVector<Conditioner> state = {
    Conditioner::Temperature,
    Conditioner::Humadity,
    Conditioner::Pressure
};
enum class TypeElement:quint8
{
    View,
    Control
};

}




QDebug operator << (QDebug debug, const ControlTypes::Conditioner &state);
QString toString(const ControlTypes::Conditioner &state);

enum class DeviceState: quint8 {
    Green,      ///< Зеленый - значит все отлично
    Yellow,     ///< Желтый - есть небольшие проблемы, но работоспособность не утрачена
    Red,        ///< Красный - все плохо!! Обрати на меня внимание!
    Unknown     ///< Состояние не определено. Блок еще не опрошен, или внешняя система (внешние системы диагностике не подлежат).
};
QString toString(const DeviceState state);
QDebug operator << (QDebug debug, const DeviceState &state);

DeviceState operator + (const DeviceState& left, const DeviceState &right);

#endif // GLOBAL_H

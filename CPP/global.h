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

enum class Server: int
{
    OFF,
    ON
};

const QVector<Conditioner> command = { Conditioner::Temperature,
                                       Conditioner::Humadity,
                                       Conditioner::Pressure,
//                                       Conditioner::OnOff,
//                                       Conditioner::Direction,
//                                       Conditioner::RequestParameters,
//                                       Conditioner::CheckConnections
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


//const QMap<Conditioner, const QVector<QString>*, const QVector<QPair<double, double>>*> mapChangeMeasurment;

const QVector<QString> stringTypeTemperature = { "°C", "°F", "K"};
const QVector<QPair<double, double>> changeTypeTemperature = {{1,0}, {1.4,32}, {1, 273.15}};
const QVector<int> stateTemperature = { 60, 100, 40, 59};
const QVector<int> borderTemperature = {5,30};

const QVector<QString> stringTypePressure = {"мм.рт.ст", "Па"};
const QVector<QPair<double, double>> changeTypePressure = { {1, 0}, {1, 133.3223684}};
const QVector<int> statePressure = { 60, 100, 40, 59};
const QVector<int> borderPressure = {0, 800};


const QVector<QString> stringTypeHumadity = {"%"};
const QVector<int> stateHumadity = { 650, 720, 40, 59};
const QVector<int> borderHumadity = {0, 100};

const QVector<QString> stringTypeServer = { "Включить", "Выключить"};
const QVector<int> stateServer = {1,1,1,1};

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

DeviceState operator + (const DeviceState& left, const DeviceState &right);

#endif // GLOBAL_H

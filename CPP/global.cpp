#include "global.h"




QDebug operator <<(QDebug debug, const ControlTypes::Conditioner &state)
{
        QDebugStateSaver saver(debug);

            debug.nospace() << toString(state);

        return debug;
}

QString toString(const ControlTypes::Conditioner &state)
{
    switch (state)
    {
    case ControlTypes::Conditioner::Temperature:
        return  "Температура";
    case ControlTypes::Conditioner::Pressure:
        return  "Давление";
    case ControlTypes::Conditioner::Humadity:
        return  "Влажность";
     case ControlTypes::Conditioner::Direction:
        return  "Направление потока воздуха";
    case ControlTypes::Conditioner::OnOff :
        return "Кондиционер";
    case ControlTypes::Conditioner::RequestParameters :
        return "Запросить данные";
    case ControlTypes::Conditioner::ComplexState:
        return "Состояние";
    default:
        return "Неизвестный тип параметра";
        break;
    }
}

DeviceState operator +(const DeviceState &left, const DeviceState &right)
{
    if (left>right) return left;
    return right;
}

QString toString(const DeviceState state)
{
    switch (state) {
    case DeviceState::Red:
        return "Red";
    case DeviceState::Yellow:
        return "Yellow";
    case DeviceState::Green:
        return "Green";
    case DeviceState::Unknown:
        return "Unknown";
    }
}

QDebug operator <<(QDebug debug, const DeviceState &state)
{
    QDebugStateSaver saver(debug);

    debug.nospace() << toString(state);

    return debug;
}

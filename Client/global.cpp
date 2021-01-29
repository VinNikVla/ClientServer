#include "global.h"


QDebug operator <<(QDebug debug, const ControlTypes::Conditioner &state)
{
        QDebugStateSaver saver(debug);

        switch (state) {
        case ControlTypes::Conditioner::Temperature:
            debug.nospace() << "Температура";
            break;
        case ControlTypes::Conditioner::Pressure:
            debug.nospace() << "Давление";
            break;
        case ControlTypes::Conditioner::Humadity:
            debug.nospace() << "Влажность";
            break;
        case ControlTypes::Conditioner::Direction:
            debug.nospace() << "Направление потока воздуха";
            break;

        case ControlTypes::Conditioner::OnOff :
            debug.nospace() << "Включение/Выключение";
            break;
        case ControlTypes::Conditioner::RequestParameters :
            debug.nospace() << "Запросить данные";
            break;
        default:
            debug.nospace() << "Неизвестный тип параметра";
            break;
        }

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
        return "Включение/Выключение";
    case ControlTypes::Conditioner::RequestParameters :
        return "Запросить данные";
    default:
        return "Неизвестный тип параметра";
        break;
    }
}

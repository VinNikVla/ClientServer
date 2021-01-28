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
        case ControlTypes::Conditioner::Request :
            debug.nospace() << "Запросить данные";
            break;
        default:
            debug.nospace() << "Неизвестный тип параметра";
            break;
        }

        return debug;
}

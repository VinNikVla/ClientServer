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
            debug.nospace() << "Направление";
            break;

        case ControlTypes::Conditioner::OnOff :
            debug.nospace() << "Включение/Выключение";
            break;
        default:
            debug.nospace() << "Неизвестный тип управления";
            break;
        }

        return debug;
}

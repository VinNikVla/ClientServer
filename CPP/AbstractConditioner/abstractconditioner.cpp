#include "abstractconditioner.h"

AbstractConditioner::AbstractConditioner(QObject *parent) : QObject(parent)
{
    com.resize(5);
}

AbstractValueModel *AbstractConditioner::getDetector(ControlTypes::Conditioner type)
{
    if(m_map.contains(type))
    {
        qDebug() << "Подключение сигналов и слотов логика" << m_map[type]->getTypeDetector();
        return m_map[type];
    }
    qDebug() << "Unknown key " << type;
}

void AbstractConditioner::slotRequest(const ControlTypes::Conditioner &typeParameter, const int value)
{
    qDebug() << typeParameter << " " << value << " " << sizeof(value);


    intToChar convert;
    convert.x = value;

    com[0] = static_cast<quint8>(typeParameter);
    com[1] = convert.ch[3];
    com[2] = convert.ch[2];
    com[3] = convert.ch[1];
    com[4] = convert.ch[0];

    emit signalSendRequest(com);
}

void AbstractConditioner::slotResponse(QString senderIP, int senderPort, QByteArray data)
{
    Q_UNUSED(senderIP)
    Q_UNUSED(senderPort)

    if(data.size() != 5)
    {
        qDebug() << "Неверный формат пакета!!!";
        return;
    }

    ControlTypes::Conditioner tmp;
    intToChar convert;

    tmp = static_cast<ControlTypes::Conditioner>(data.at(0));

        for(int i = sizeof(int) - 1; i >= 0; i--)
        {
            convert.ch[i] = data.at(sizeof(int) - i);
        }

        qDebug() << tmp << " " << convert.x;
        if(m_map.contains(tmp))
        {
            m_map[tmp]->slotSetValue(convert.x);
        }
}

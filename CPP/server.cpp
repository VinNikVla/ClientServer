#include "server.h"

Server::Server(const QVector<QString> *_listMeasurments, const ControlTypes::Conditioner &_typeDetector, const QVector<int> *_border, QObject *parent):
    ValueModel(_listMeasurments, _typeDetector, _border, parent)
{
    m_typeMeasurments = "Выключить";
    m_value = 1;
}

void Server::slotChangeTypeValue(const QString &type)
{
    if(!checkAvailabilityMeasurments(type))
    {
        qDebug() << "Вы пытаетесь установить неизвестный тип измерений";
        return;
    }

    qDebug() << typeid(this).name() << m_value << type;

    if(m_value)
    {
        m_typeMeasurments = "Выключить";
    }
    else
    {
        m_typeMeasurments = "Включить";
    }



    m_typeMeasurments = type;
    emit signalValueChanged(m_typeMeasurments);
    emit signalServerConnected();
}

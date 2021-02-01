#pragma once

#include <QObject>
#include "temperature.h"
#include "humadity.h"
#include "pressure.h"
#include "global.h"
#include "server.h"
#include "UDP/udpserver.h"

typedef union {
    int x;
    quint8 ch[4];

} intToChar;

class ConditionerServer : public QObject
{
    Q_OBJECT
public:
    explicit ConditionerServer(const UDPclient* udpSender, QObject *parent = nullptr);

    ValueModel* getDetector(ControlTypes::Conditioner type);

public slots:
    void sendCommandToClient(const ControlTypes::Conditioner& typeParameter, const int value);
    void requestFromClient(QString senderIP, int senderPort, QByteArray data);

signals:
    void sendResponseToClient(QByteArray data);

private:

    QString m_ownIP;
    quint16 m_ownPort;
    QString m_IP;
    quint16 m_Port;

    ControlTypes::Server m_state;


    QMap<ControlTypes::Conditioner, ValueModel*> m_map;


    QByteArray com;//отправляемый массив данных на cервер/клиент

};


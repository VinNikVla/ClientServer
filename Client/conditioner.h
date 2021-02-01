#ifndef CONDITIONER_H
#define CONDITIONER_H

#include <QObject>
#include <QString>
#include <QMap>
#include <chrono>
#include "global.h"
#include "settings.h"
#include <QByteArray>

#include "temperature.h"
#include "pressure.h"
#include "humadity.h"
#include "server.h"

#include <QtGlobal>

typedef union {
    int x;
    quint8 ch[4];

} intToChar;

class Conditioner : public QObject
{
    Q_OBJECT
public:
    Conditioner(Settings* _set, const QString& _ip, const quint16& _port, QObject* parent=nullptr);

    ValueModel* getDetector(ControlTypes::Conditioner type);

public slots:
    void sendCommand(const ControlTypes::Conditioner& typeParameter, const int value);
    void responseFromServer(QString senderIP, int senderPort, QByteArray data);

    void slotChangeState();

signals:
    void sendCommandToServer(QByteArray data, QString& receiver);
    void signalChangeComlexState(const DeviceState& state);

private:
    Settings* m_set;
    QString m_ip;
    quint16 m_port;

    QMap<ControlTypes::Conditioner, ValueModel*> m_map;


    QByteArray com;//отправляемый массив данных на cервер/клиент

};

#endif // CONDITIONER_H

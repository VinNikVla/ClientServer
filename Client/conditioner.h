#ifndef CONDITIONER_H
#define CONDITIONER_H

#include <QObject>
#include <QString>
#include <QMap>
#include <chrono>
#include "global.h"
#include "settings.h"
#include <QByteArray>

typedef union {
    int x;
    quint8 ch[4];

} intToChar;

class Conditioner : public QObject
{
    Q_OBJECT
public:
    Conditioner(Settings* _set, const QString& _ip, const quint16& _port, QObject* parent=nullptr);

public slots:
    void changeValue(const ControlTypes::Conditioner& typeParameter, const int value);
    void slotChangeTypeTemperature(const QString& type);
    void slotChangeTypePressure(const QString& type);
    void slotChangeTypeHumadity(const QString& type);

    void sendCommand(const ControlTypes::Conditioner& typeParameter, const int value);
    void responseFromServer(QString senderIP, int senderPort, QByteArray data);


signals:
    void signalTemperatureChanged(const QString value);
    void signalPressureChanged(const QString value);
    void signalHumadityChanged(const QString value);

    void sendCommandToServer(QByteArray data, QString& receiver);

private:
    Settings* m_set;

    double m_temperature;
    QString typeTemperature;

    double m_pressure;
    QString typePressure;

    double m_humadity;
    QString typeHumadity;

    QMap<ControlTypes::Conditioner, double*> m_map;
    QString m_ip;
    quint16 m_port;

    QByteArray com;//отправляемый массив данных на cервер/клиент

};

#endif // CONDITIONER_H

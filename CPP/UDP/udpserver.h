#pragma once

#include <QObject>
#include <QUdpSocket>
#include <QNetworkDatagram>
#include <QDebug>

class UDPclient : public QObject
{
    Q_OBJECT
public:
    UDPclient(QString _ownIp, QString _ip, int _port, QObject *parent = nullptr, int _ownPort=0);
    void Prepare();
signals:
    void receiveData(QString senderIp, int senderPort, QByteArray ba);
   // void Message(Log::LoggerMsg lm,  QString message);
public slots:
    void read();
    void sendDataTo(QByteArray ds);
private:
    QUdpSocket *sock=nullptr;
    bool Connect();
    bool IamReady;
    QString ip;
    QString ownIp;
    int port;
    int ownPort;
    quint8 udpStillNotOpen=99;

};


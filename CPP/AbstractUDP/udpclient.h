#ifndef UDPCLIENT_H
#define UDPCLIENT_H

#include <QObject>
#include <QUdpSocket>
#include <QNetworkDatagram>
#include <QTimer>

class UDPCLient : public QObject
{
    Q_OBJECT
public:
    explicit UDPCLient(QString _ownIp, int _ownPort, QString _ip, int _port, QObject *parent = nullptr);
    void Prepare();

private:
    QUdpSocket *sock=nullptr;
    bool Connect();
    bool IamReady;
    QString m_ownIp;
    int m_ownPort;
    int m_port;
    QString m_ip;
    QTimer* timer=nullptr;

public slots:
    void read();
    void sendDataTo(QByteArray ds);

signals:
    void receiveData(QString senderIp, int senderPort, QByteArray ba);
    void receiveDataClear(QByteArray ba);
    //void Message(Log::LoggerMsg lm,  QString message);
};

#endif // UDPCLIENT_H

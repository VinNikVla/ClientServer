#include "udpclient.h"

UDPCLient::UDPCLient(QString _ip, int _port, QObject *parent) :
    QObject(parent),
    IamReady(false),
    port(_port),
    ip(_ip)
{
    sock=new QUdpSocket(this);
    timer=new QTimer(this);
    timer->setInterval(500);
    connect(timer,&QTimer::timeout,this,&UDPCLient::Connect);
    timer->start();
}

bool UDPCLient::Connect()
{
    if (!sock->bind(QHostAddress(ip),static_cast<quint16>(port),QAbstractSocket::DefaultForPlatform))
    {
       // emit Message(Log::Warning,QString("UDP: не удалось привязаться к порту: %1").arg(sock->errorString()));
        qDebug() << "UDP: не удалось привязаться к порту" << " " << sock->errorString();
        return false;
    }
    //emit Message(Log::Warning,"UDP: подключение открыто");
    connect(sock,&QUdpSocket::readyRead,this,&UDPCLient::read);
    if (timer)timer->stop();
    return true;
}

void UDPCLient::sendDataTo(QByteArray ds, QString &kuIp)
{
    bool result;
    result=(ds.length()==sock->writeDatagram(ds,QHostAddress(kuIp),static_cast<quint16>(port + 1)));
    if (!result)
        qDebug() << "UDP: не удалось отправить пакет" << " " << sock->errorString();
        //emit Message(Log::Warning,QString("UDP: не удалось отправить пакет: %1").arg(sock->errorString()));
}

void UDPCLient::read()
{
    while (sock->hasPendingDatagrams())
    {
        QNetworkDatagram datagram=sock->receiveDatagram();
        QString SenderIP=datagram.senderAddress().toString();
        int SenderPort=datagram.senderPort();
        QByteArray data=datagram.data();
        emit receiveData(SenderIP,SenderPort, data);
        emit receiveDataClear(data);
    }
}


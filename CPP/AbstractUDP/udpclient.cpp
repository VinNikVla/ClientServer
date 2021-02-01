#include "udpclient.h"

UDPCLient::UDPCLient(QString _ownIp, int _ownPort, QString _ip, int _port, QObject *parent):
    QObject(parent),
    IamReady(false),
    m_ownIp(_ownIp),
    m_ownPort(_ownPort),
    m_port(_port),
    m_ip(_ip)
{
    sock=new QUdpSocket(this);
    timer=new QTimer(this);
    timer->setInterval(500);
    connect(timer,&QTimer::timeout,this,&UDPCLient::Connect);
    timer->start();
}

bool UDPCLient::Connect()
{
    if (!sock->bind(QHostAddress(m_ownIp),static_cast<quint16>(m_ownPort),QAbstractSocket::DefaultForPlatform))
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

void UDPCLient::sendDataTo(QByteArray ds)
{
    bool result;
    result=(ds.length()==sock->writeDatagram(ds,QHostAddress(m_ip),static_cast<quint16>(m_port)));
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


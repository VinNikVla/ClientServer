#include "udpserver.h"

UDPclient::UDPclient(QString _ownIp, QString _ip, int _port, QObject *parent, int _ownPort) :
   QObject(parent),
   IamReady(false),
   ip(_ip),
   ownIp(_ownIp),
   port(_port),
   ownPort(_ownPort!=0? _ownPort : _port)
{
    sock=new QUdpSocket(this);
    Connect();
}

bool UDPclient::Connect()
{
    //ownIP
    if (!sock->bind(QHostAddress(ownIp),static_cast<quint16>(ownPort),QAbstractSocket::DefaultForPlatform))
    {
        udpStillNotOpen++;
        if (udpStillNotOpen>=100)
        {
            udpStillNotOpen=0;
            qDebug() << "UDP: не удалось привязаться к порту" << ownPort;
            qDebug() << sock->errorString();
            //emit Message(Log::Warning,QString("UDP: не удалось привязаться к порту %1:%2 -  %3").arg(ownIp,QString::number(ownPort), sock->errorString()));
        }
        return false;
    }
    udpStillNotOpen=99;
    //emit Message(Log::Warning,"UDP: подключение открыто");
    qDebug() << "UDP: подключение открыто!";
    connect(sock,&QUdpSocket::readyRead,this,&UDPclient::read);
    return true;
}

void UDPclient::sendDataTo(QByteArray ds)
{
    bool result;
    if (!IamReady) IamReady=Connect();
    if (IamReady)
    {
        result=(ds.length()==sock->writeDatagram(ds,QHostAddress(ip),static_cast<quint16>(port)));
        if (!result)
        {   qDebug() << "UDP: не удалось отпрвить пакет " << sock->errorString();
            //emit Message(Log::LoggerMsg::Warning,QString("UDP: не удалось отправить пакет: %1").arg(sock->errorString()));
        }
        else
        {
            qDebug() << "Packeg sent!";
            //emit Message(Log::LoggerMsg::Info,QString("UDP: отправлен пакет %1:%2 %3").arg(ip,QString::number(port),ds.toHex(' ')));
        }
    }
}

void UDPclient::read()
{
    while (sock->hasPendingDatagrams())
    {
        QNetworkDatagram datagram=sock->receiveDatagram();
        QByteArray datagramm=datagram.data();
        if (datagramm.length()>0)
        {
            qDebug() << datagramm;
            emit receiveData(datagramm);
        }
    }

}

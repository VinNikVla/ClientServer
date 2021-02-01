#ifndef ABSTRACTCONDITIONER_H
#define ABSTRACTCONDITIONER_H

#include <QObject>
#include "global.h"
#include "AbstractValueModel/ChangeStateModel/ChangeMeasurmentsModel/changemeasurment.h"

typedef union {
    int x;
    quint8 ch[4];

} intToChar;

class AbstractConditioner : public QObject
{
    Q_OBJECT
public:
    explicit AbstractConditioner(QObject *parent = nullptr);
    AbstractValueModel* getDetector(ControlTypes::Conditioner type);
signals:
    void signalSendRequest(QByteArray ba);
public slots:
    void slotRequest(const ControlTypes::Conditioner &typeParameter, const int value);
    void slotResponse(QString senderIP, int senderPort, QByteArray data);

protected:
    QMap<ControlTypes::Conditioner, AbstractValueModel*> m_map;
private:
    QByteArray com;
};

#endif // ABSTRACTCONDITIONER_H

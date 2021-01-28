//#pragma once

//#include <QObject>
//#include "global.h"

////https://evileg.com/ru/post/305/ the same

//class ValueModel :public QObject
//{
//    Q_OBJECT
//public:
//    ValueModel(QObject* parent = nullptr,DeviceState st = DeviceState::Unknown, QString val="НЕТ");
//    Q_PROPERTY(int state READ getState  NOTIFY  stateChanged)
//    int getState() const {return static_cast<int>(m_state);}
//    DeviceState getDeviceState() const;
//    void setState(DeviceState ds);

//    Q_PROPERTY(QString value READ getValue WRITE setValue NOTIFY valueChanged)
//    QString getValue() const {return m_value;}
//    void setValue(QString val);
//    void setValue(double val,int precision=1);
//    void setValue(int val);
//signals:
//    void stateChanged(DeviceState state);
//    void  valueChanged();
//protected:
//    DeviceState m_state;
//    QString m_value;
//};

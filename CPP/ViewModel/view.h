#ifndef VIEW_H
#define VIEW_H

#include <QVector>
#include <QWidget>
#include <QSlider>
#include <QPushButton>
#include <QLayout>
#include <QLabel>
#include <QLCDNumber>
#include <QMenu>
#include <QMenuBar>

#include <QDebug>
#include <QAction>
#include "global.h"

enum class TypeElement:quint8
{
    View,
    Control
};

class View : public QWidget
{
    Q_OBJECT
public:
    explicit View(const ControlTypes::Conditioner& _typeDetector, const bool avaliableMenu, const QVector<QString>* _measurement = nullptr, QWidget *parent = nullptr);
    ControlTypes::Conditioner getTypeDetector() const;

signals:
    void signalChangeTypeMeasurements(const QString& type);

public slots:
    void slotActivated(QAction* pAction);
    void slotChangeValue(const QString& value);


private:
    ControlTypes::Conditioner m_typeDetector;
    bool mustPushed;
    const QVector<QString>* m_measurement;
    QPushButton* button;
    QLabel* type;
    QMenu* menu;
    QLayout* layout;



    void createButton();
    void createMenu();


};

#endif // VIEW_H

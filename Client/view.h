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
    explicit View(const QString& _name, const bool avaliableMenu, QWidget *parent = nullptr, const QVector<QString>* _measurement = nullptr);
    QString getName() const;
signals:
    void signalChangeTypeMeasurements(const QString& type);

public slots:
    void slotActivated(QAction* pAction);
    void slotChangeValue(const QString& value);


private:
    QPushButton* button;
    QLabel* type;
    QMenu* menu;
    QLayout* layout;
    QString m_name;
    bool mustPushed;
    const QVector<QString>* m_measurement;


    void createButton();
    void createMenu();


};

#endif // VIEW_H

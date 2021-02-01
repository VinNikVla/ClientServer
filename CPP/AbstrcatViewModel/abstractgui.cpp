#include "abstractgui.h"

AbstractGUI::AbstractGUI(const ControlTypes::Conditioner &_typeDetector, QWidget *parent):
    QWidget(parent),
    m_typeDetector(_typeDetector)
{

}

ControlTypes::Conditioner AbstractGUI::getTypeDetector() const
{
    return m_typeDetector;
}

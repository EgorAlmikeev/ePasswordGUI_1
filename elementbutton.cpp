#include "elementbutton.h"

ElementButton::ElementButton(QWidget *parent) : QWidget(parent)
{
    p_central_widget = new QPushButton;
    p_central_layout = new QVBoxLayout;

    setLayout(p_central_layout);
    p_central_layout->addWidget(p_central_widget);

    p_central_layout->setMargin(0);
    p_central_layout->setSpacing(0);
}

void ElementButton::setPairWidget(ElementInfoWidget *pair)
{
    p_pair_widget = pair;
}

void ElementButton::elementButtonClicked()
{
    emit sendPairWidget(p_pair_widget);
}

void ElementButton::setText(QString text)
{
    p_central_widget->setText(text);
}

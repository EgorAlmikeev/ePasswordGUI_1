#include "elementbutton.h"
#include "mainwindow.h"
#include <QDebug>

ElementButton::ElementButton(QWidget *parent) : QWidget(parent)
{
    p_central_widget = new QPushButton;
    p_central_layout = new QVBoxLayout;

    setLayout(p_central_layout);
    p_central_layout->addWidget(p_central_widget);

    p_central_layout->setMargin(0);
    p_central_layout->setSpacing(0);

    p_central_widget->setFixedWidth(190);
    p_central_widget->setFixedHeight(MainWindow::element_buttons_height);
    setFixedHeight(MainWindow::element_buttons_height);

    p_central_widget->setCursor(Qt::OpenHandCursor);
    p_central_layout->setAlignment(Qt::AlignCenter);
    p_central_widget->setStyleSheet("border : 1px solid black; border-radius : 15px; background-color: rgba(255, 255, 255, 0);");

    connect(p_central_widget, SIGNAL(clicked(bool)), SLOT(elementButtonClicked()));
}

void ElementButton::setPairWidget(ElementInfoWidget *pair)
{
    p_pair_widget = pair;
}

void ElementButton::elementButtonClicked()
{
    qDebug("element button clicked");
    qDebug() << p_pair_widget->objectName();
    emit sendPairWidget(p_pair_widget);
}

void ElementButton::setText(QString text)
{
    p_central_widget->setText(text);
    button_text = text;
}

bool element_buttons_compare(ElementButton* b1, ElementButton* b2)
{
    return b1->button_text < b2->button_text ? true : false;
}

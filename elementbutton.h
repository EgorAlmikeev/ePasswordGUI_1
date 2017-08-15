#ifndef ELEMENTPUTTON_H
#define ELEMENTPUTTON_H

#include <QWidget>
#include <QPushButton>
#include <QVBoxLayout>

#include "elementinfowidget.h"

class ElementButton : public QWidget
{
    Q_OBJECT
public:
    explicit ElementButton(QWidget *parent = nullptr);

private:

    QPushButton *p_central_widget;
    QVBoxLayout *p_central_layout;

public:

    QString button_text;
    ElementInfoWidget *p_pair_widget;

signals:

    void sendPairWidget(ElementInfoWidget*);

public slots:

    void setPairWidget(ElementInfoWidget*);
    void elementButtonClicked();
    void setText(QString);

};

bool element_buttons_compare(ElementButton* b1, ElementButton* b2);

#endif // ELEMENTPUTTON_H

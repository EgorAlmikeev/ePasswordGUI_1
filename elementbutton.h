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
    ElementInfoWidget *p_pair_widget;
    QVBoxLayout *p_central_layout;

signals:

    void sendPairWidget(ElementInfoWidget*);

public slots:

    void setPairWidget(ElementInfoWidget*);
    void elementButtonClicked();
    void setText(QString);

};

#endif // ELEMENTPUTTON_H

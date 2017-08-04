#ifndef USERPASSWORDINPUT_H
#define USERPASSWORDINPUT_H

#include <QWidget>
#include <QGridLayout>
#include <QCheckBox>
#include <QLineEdit>
#include <QLabel>

class UserPasswordInput : public QWidget
{
    Q_OBJECT
public:
    explicit UserPasswordInput(QWidget *parent = nullptr);

    QGridLayout *p_central_grid_layout;

signals:

public slots:
};

#endif // USERPASSWORDINPUT_H

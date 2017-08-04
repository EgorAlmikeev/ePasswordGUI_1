#ifndef USERTEXTINPUT_H
#define USERTEXTINPUT_H

#include <QWidget>
#include <QPushButton>
#include <QLineEdit>
#include <QLabel>
#include <QGridLayout>

class UserNameInput : public QWidget
{
    Q_OBJECT
public:
    explicit UserNameInput(QWidget *parent = nullptr);

    QGridLayout *p_central_grid_layout;
    QLabel *p_label;
    QLineEdit *p_line_edit;
    QPushButton *p_next_button;

    int text_minimum;

signals:

    void sendName(QString);

public slots:

    void setText(QString);

    void setNameMaximumLength(int);
    void setNameMinimumLength(int);

    void nextButtonClicked();

    void checkText();
    void clearInput();

};

#endif // USERTEXTINPUT_H

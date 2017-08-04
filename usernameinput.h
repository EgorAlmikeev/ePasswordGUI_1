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
    QPushButton *p_close_button;

    int text_minimum;

signals:

    void sendText(QString);

public slots:

    void setText(QString);
    void setTextMaximum(int);
    void setTextMinimum(int);
    void closeButtonClicked();
    void checkText();
    void clearInput();

};

#endif // USERTEXTINPUT_H

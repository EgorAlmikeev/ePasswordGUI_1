#ifndef USERPASSWORDINPUT_H
#define USERPASSWORDINPUT_H

#include <QWidget>
#include <QGridLayout>
#include <QCheckBox>
#include <QLineEdit>
#include <QLabel>
#include <QPushButton>
#include <QSlider>

#include "mainwindow.h"

class UserPasswordInput : public QWidget
{
    Q_OBJECT
public:
    explicit UserPasswordInput(QWidget *parent = nullptr);

    QGridLayout *p_central_grid_layout;

    QPushButton *p_generate_button;
    QPushButton *p_next_button;

    QLabel *p_label;
    QLineEdit *p_line_edit;

    QCheckBox *p_letters_checkbox;
    QCheckBox *p_digits_checkbox;
    QCheckBox *p_specials_checkbox;

    QCheckBox *p_user_input_checkbox;

    QSlider *p_slider;
    QLabel *p_slider_display;

    QString password;

    int password_minimum_length;
    short password_maximum_length;




    //password simbols generation
    std::string generatePassword();
    char *p_password_simbols = nullptr;

    bool setPasswordSimbolsDigits();
    bool setPasswordSimbolsLetters();
    bool setPasswordSimbolsSpecials();
    bool setPasswordSimbolsDigitsLetters();
    bool setPasswordSimbolsDigitsSpecials();
    bool setPasswordSimbolsLettersSpecials();
    bool setPasswordSimbolsDigitsLettersSpecials();
    //end of password simbols generation

signals:

    void sendPassword(QString);

public slots:

    void userPasswordCheckBoxToggled();
    void checkPassword();

    void generateButtonClicked();
    void nextButtonClicked();

    void setPasswordMaximumLength(int);
    void setPasswordMinimumLength(int);

    void setText(QString);

    void clearInput();
};

#endif // USERPASSWORDINPUT_H

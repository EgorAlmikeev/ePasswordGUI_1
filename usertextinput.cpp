#include "usertextinput.h"

UserTextInput::UserTextInput(QWidget *parent) : QWidget(parent)
{
    p_central_grid_layout = new QGridLayout;
    p_label = new QLabel;
    p_line_edit = new QLineEdit;
    p_close_button = new QPushButton("close");

    setLayout(p_central_grid_layout);

    p_central_grid_layout->addWidget(p_label, 0, 0, 1, 3);
    p_central_grid_layout->addWidget(p_line_edit, 1, 0, 1, 2);
    p_central_grid_layout->addWidget(p_close_button, 1, 3, 1, 1);

    connect(p_close_button, SIGNAL(clicked(bool)), SLOT(closeButtonClicked()));
    connect(p_line_edit, SIGNAL(textEdited(QString)), SLOT(checkText()));

    p_close_button->setEnabled(false);
}

void UserTextInput::closeButtonClicked()
{
    emit sendText(p_line_edit->text());
    close();
}

void UserTextInput::setText(QString text)
{
    p_label->setText(text);
}

void UserTextInput::setTextMaximum(int max)
{
    p_line_edit->setMaxLength(max);
}

void UserTextInput::setTextMinimum(int min)
{
    text_minimum = min;
}

void UserTextInput::checkText()
{
    if(p_line_edit->text().length() <= text_minimum)
        p_close_button->setEnabled(true);
    else
        p_close_button->setEnabled(false);
}

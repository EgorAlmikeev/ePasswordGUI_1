#include "usernameinput.h"
#include "mainwindow.h"

UserNameInput::UserNameInput(QWidget *parent) : QWidget(parent)
{
    qDebug() << "name input constructor";
    p_central_grid_layout = new QGridLayout;
    p_label = new QLabel;
    p_line_edit = new QLineEdit;
    p_next_button = new QPushButton("Next");

    setLayout(p_central_grid_layout);

    p_central_grid_layout->addWidget(p_label, 0, 0, 1, 3);
    p_central_grid_layout->addWidget(p_line_edit, 1, 0, 1, 2);
    p_central_grid_layout->addWidget(p_next_button, 1, 2, 1, 1);

    connect(p_next_button, SIGNAL(clicked(bool)), SLOT(nextButtonClicked()));
    connect(p_line_edit, SIGNAL(textEdited(QString)), SLOT(checkText()));

    p_next_button->setEnabled(false);

    p_central_grid_layout->setSpacing(0);
    p_central_grid_layout->setMargin(0);

    p_label->setFont(QFont("phosphate", 35));
    p_label->setAlignment(Qt::AlignCenter);
    p_label->setFixedHeight(60);

    p_line_edit->setFixedHeight(60);
    p_line_edit->setFixedWidth(325);
    p_line_edit->setFont(QFont("Arial", 30));
    p_line_edit->setFocus();

    p_next_button->setFixedSize(100, 70);

    p_next_button->setCursor(Qt::OpenHandCursor);
}

void UserNameInput::nextButtonClicked()
{
    qDebug() << "name input next button clicked";
    emit sendName(p_line_edit->text());
    setVisible(false);
}

void UserNameInput::setText(QString text)
{
    qDebug() << "name input set text " << text;
    p_label->setText(text);
}

void UserNameInput::setNameMaximumLength(int max)
{
    qDebug() << "name input set name max " << max;
    p_line_edit->setMaxLength(max);
}

void UserNameInput::setNameMinimumLength(int min)
{
    qDebug() << "name input set name minimum " << min;
    text_minimum = min;
}

void UserNameInput::checkText()
{
    qDebug() << "name input check text";
    if(p_line_edit->text().length() >= text_minimum && !p_line_edit->text().contains(' ')/* && !MainWindow::p_core->element_multi_map.contains(p_line_edit->text() + '\n')*/)
    {
        p_next_button->setEnabled(true);
        p_line_edit->setStyleSheet( "color : black;" );
    }
    else
    {
        p_next_button->setEnabled(false);
        p_line_edit->setStyleSheet( "color : red;" );
    }
}

void UserNameInput::clearInput()
{
    qDebug() << "name input clear input";
    p_line_edit->clear();
    checkText();
}

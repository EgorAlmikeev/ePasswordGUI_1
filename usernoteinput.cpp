#include "usernoteinput.h"

UserNoteInput::UserNoteInput(QWidget *parent) : QWidget(parent)
{
    p_central_vertical_layout = new QVBoxLayout;
    setLayout(p_central_vertical_layout);

    p_label = new QLabel;
    p_text_edit = new QTextEdit;
    p_next_button = new QPushButton("Next");

    p_central_vertical_layout->addWidget(p_label);
    p_central_vertical_layout->addWidget(p_text_edit);
    p_central_vertical_layout->addWidget(p_next_button);

    p_label->setFont(QFont("phosphate", 35));
    p_label->setAlignment(Qt::AlignCenter);
    p_label->setFixedHeight(60);

    p_next_button->setFixedHeight(70);

    p_text_edit->setFont(QFont("Arial", 20));

    connect(p_next_button, SIGNAL(clicked(bool)), SLOT(nextButtonClicked()));
}

void UserNoteInput::nextButtonClicked()
{
    QString buffer = p_text_edit->toPlainText();

    if(buffer.contains('\n'))
        for(int i = 0; i < buffer.length(); ++i)
            if(buffer.at(i) == '\n')
                buffer[i] = ' ';

    emit sendNote(buffer);
    setVisible(false);
}

void UserNoteInput::setText(QString string)
{
    p_label->setText(string);
}

void UserNoteInput::clearInput()
{}

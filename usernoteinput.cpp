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
    p_central_vertical_layout->setAlignment(Qt::AlignCenter);

    p_label->setFont(QFont("phosphate", 35));
    p_label->setAlignment(Qt::AlignCenter);
    p_label->setFixedHeight(60);

    p_next_button->setFixedHeight(70);

    p_text_edit->setFixedWidth(300);
    p_text_edit->setFont(QFont("Arial", 20));

    p_next_button->setCursor(Qt::OpenHandCursor);

    connect(p_next_button, SIGNAL(clicked(bool)), SLOT(nextButtonClicked()));
}

void UserNoteInput::nextButtonClicked()
{
    if(p_text_edit->toPlainText().length() == 0)
        p_text_edit->setText(" ");

    std::string temp = p_text_edit->toPlainText().toStdString();

    //delete of last \n simbols
    if(temp.at(temp.length() - 1) == '\n')
    {
        for(int i = temp.length() - 1; temp.at(i) == '\n'; --i)
            temp.erase(i, 1);
    }

    //repplace of \n simbols inside the text for one \n simbol
    for(int i = 0, j = 0; i < temp.length(); ++i, j = 0)
    {
        if(temp.at(i) == '\n')
        {
            for(j = i + 1; temp.at(j) == '\n'; ++j);
            temp.replace(i, j - i, "\n");
        }
    }

    for(int i = 0; i < temp.length(); ++i)
    {
        if(temp.at(i) == '\n')
            temp.replace(i, 1, "\a");
    }

    QString buffer = QString::fromStdString(temp);

    emit sendNote(buffer);
    setVisible(false);
}

void UserNoteInput::setText(QString string)
{
    p_label->setText(string);
}

void UserNoteInput::clearInput()
{
    p_text_edit->clear();
    p_text_edit->setFocus();
}

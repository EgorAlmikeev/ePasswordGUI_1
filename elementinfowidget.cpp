#include "elementinfowidget.h"
#include "elementbutton.h"

ElementInfoWidget::ElementInfoWidget(QWidget *parent) : QWidget(parent)
{
    //creating widgets
    p_central_vertical_layout = new QBoxLayout(QBoxLayout::TopToBottom);

    p_name_horizontal_layout = new QBoxLayout(QBoxLayout::LeftToRight);
    p_password_horizontal_layout = new QBoxLayout(QBoxLayout::LeftToRight);
    p_note_horizontal_layout = new QBoxLayout(QBoxLayout::LeftToRight);
    p_remove_button_horizontal_layout = new QBoxLayout(QBoxLayout::LeftToRight);

    p_name_copy_button = new QPushButton;
    p_password_copy_button = new QPushButton;
    p_note_copy_button = new QPushButton;

    p_name_edit_button = new QPushButton;
    p_password_edit_button = new QPushButton;
    p_note_edit_button = new QPushButton;

    p_remove_button = new QPushButton;

    p_name_text_edit = new QTextEdit;
    p_password_text_edit = new QTextEdit;
    p_note_text_edit = new QTextEdit;

    setFixedWidth(420);

    p_central_vertical_layout->setMargin(5);

    p_name_text_edit->setReadOnly(true);
    p_password_text_edit->setReadOnly(true);
    p_note_text_edit->setReadOnly(true);

    //placement
    setLayout(p_central_vertical_layout);

    p_name_horizontal_layout->setAlignment(Qt::AlignCenter);
    p_name_horizontal_layout->addWidget(p_name_text_edit);
    p_name_horizontal_layout->addWidget(p_name_copy_button);
    p_name_horizontal_layout->addWidget(p_name_edit_button);

    p_password_horizontal_layout->setAlignment(Qt::AlignCenter);
    p_password_horizontal_layout->addWidget(p_password_text_edit);
    p_password_horizontal_layout->addWidget(p_password_copy_button);
    p_password_horizontal_layout->addWidget(p_password_edit_button);

    p_note_horizontal_layout->setAlignment(Qt::AlignCenter);
    p_note_horizontal_layout->addWidget(p_note_text_edit);
    p_note_horizontal_layout->addWidget(p_note_copy_button);
    p_note_horizontal_layout->addWidget(p_note_edit_button);

    p_remove_button_horizontal_layout->addWidget(p_remove_button);

    p_central_vertical_layout->addSpacing(20);
    p_central_vertical_layout->addLayout(p_name_horizontal_layout);
    p_central_vertical_layout->addLayout(p_password_horizontal_layout);
    p_central_vertical_layout->addLayout(p_note_horizontal_layout);
    p_central_vertical_layout->addSpacing(20);
    p_central_vertical_layout->addLayout(p_remove_button_horizontal_layout);
    p_central_vertical_layout->addSpacing(20);

    //buttons settings
    //icon
    QPixmap copy_pix(":/images/copy.png");
    p_name_copy_button->setIcon(copy_pix);
    p_password_copy_button->setIcon(copy_pix);
    p_note_copy_button->setIcon(copy_pix);

    p_name_copy_button->setIconSize(QSize(40, 40));
    p_password_copy_button->setIconSize(QSize(40, 40));
    p_note_copy_button->setIconSize(QSize(40, 40));

    QPixmap edit_pix(":/images/edit.png");
    p_name_edit_button->setIcon(edit_pix);
    p_password_edit_button->setIcon(edit_pix);
    p_note_edit_button->setIcon(edit_pix);

    p_name_edit_button->setIconSize(QSize(40, 40));
    p_password_edit_button->setIconSize(QSize(40, 40));
    p_note_edit_button->setIconSize(QSize(40, 40));

    QPixmap remove_pix(":/images/remove.png");
    p_remove_button->setIcon(remove_pix);
    p_remove_button->setIconSize(remove_pix.size() / 3);

    //size
    p_name_copy_button->setFixedSize(QSize(40, 40));
    p_password_copy_button->setFixedSize(QSize(40, 40));
    p_note_copy_button->setFixedSize(QSize(40, 40));

    p_name_edit_button->setFixedSize(QSize(40, 40));
    p_password_edit_button->setFixedSize(QSize(40, 40));
    p_note_edit_button->setFixedSize(QSize(40, 40));
    p_remove_button->setFixedSize(remove_pix.size() / 3);

    //flat
    p_name_copy_button->setFlat(true);
    p_password_copy_button->setFlat(true);
    p_note_copy_button->setFlat(true);

    p_name_edit_button->setFlat(true);
    p_password_edit_button->setFlat(true);
    p_note_edit_button->setFlat(true);

    p_remove_button->setFlat(true);

    //cursor
    p_name_copy_button->setCursor(Qt::OpenHandCursor);
    p_password_copy_button->setCursor(Qt::OpenHandCursor);
    p_note_copy_button->setCursor(Qt::OpenHandCursor);

    p_name_edit_button->setCursor(Qt::OpenHandCursor);
    p_password_edit_button->setCursor(Qt::OpenHandCursor);
    p_note_edit_button->setCursor(Qt::OpenHandCursor);

    p_remove_button->setCursor(Qt::OpenHandCursor);

    //labels settings
    p_name_text_edit->setFrameStyle(QFrame::NoFrame);
    p_password_text_edit->setFrameStyle(QFrame::NoFrame);
    p_note_text_edit->setFrameStyle(QFrame::NoFrame);

    p_name_text_edit->setStyleSheet("border : 1px solid black; border-radius : 15px; background-color: rgba(255, 255, 255, 0);");
    p_password_text_edit->setStyleSheet("border : 1px solid black; border-radius : 15px; background-color: rgba(255, 255, 255, 0);");
    p_note_text_edit->setStyleSheet("border : 1px solid black; border-radius : 15px; background-color: rgba(255, 255, 255, 0);");

    p_name_text_edit->setFixedSize(270, 70);
    p_password_text_edit->setFixedSize(270, 70);
    p_note_text_edit->setFixedSize(270, 120);

    p_name_text_edit->setAlignment(Qt::AlignCenter);
    p_password_text_edit->setAlignment(Qt::AlignCenter);
    p_note_text_edit->setAlignment(Qt::AlignTop);

    p_name_text_edit->setFont(QFont("Arial", 20));
    p_password_text_edit->setFont(QFont("Arial", 20));
    p_note_text_edit->setFont(QFont("Arial", 20));

    //connections
    connect(p_name_copy_button, SIGNAL(clicked(bool)), SLOT(nameCopyButtonClicked()));
    connect(p_password_copy_button, SIGNAL(clicked(bool)), SLOT(passwordCopyButtonClicked()));
    connect(p_note_copy_button, SIGNAL(clicked(bool)), SLOT(noteCopyButtonClicked()));

    connect(p_name_edit_button, SIGNAL(clicked(bool)), SIGNAL(nameEditButtonClicked()));
    connect(p_password_edit_button, SIGNAL(clicked(bool)), SIGNAL(passwordEditButtonClicked()));
    connect(p_note_edit_button, SIGNAL(clicked(bool)), SIGNAL(noteEditButtonClicked()));

    connect(p_remove_button, SIGNAL(clicked(bool)), SIGNAL(removeButtonClicked()));

    p_name_copy_button->setToolTip("Copy name");
    p_password_copy_button->setToolTip("Copy password");
    p_note_copy_button->setToolTip("Copy note");

    p_name_edit_button->setToolTip("Edit name");
    p_password_edit_button->setToolTip("Edit password");
    p_note_edit_button->setToolTip("Edit note");

    p_remove_button->setToolTip("Remove this save");
}

ElementInfoWidget::~ElementInfoWidget()
{}

void ElementInfoWidget::setPairButton(ElementButton *p_button)
{
    p_pair_button = p_button;
}

void ElementInfoWidget::setName(QString _name)
{
    name = _name;
    p_name_text_edit->setText("Name:\n" + _name);
    p_pair_button->setText(_name);

    emit nameEdited();
}

void ElementInfoWidget::setPassword(QString _password)
{
    password = _password;
    p_password_text_edit->setText("Password:\n" + _password);

    emit passwordEdited();
}

void ElementInfoWidget::setNote(QString _note)
{
    std::string temp = _note.toStdString();

    for(int i = 0; i < temp.length(); ++i)
    {
        if(temp.at(i) == '$' && temp.at(i + 1) == '$')
            temp.replace(i++, 2, "$");
        else if(temp.at(i) == '$')
            temp.replace(i, 1, "\n");
    }

    note = QString::fromStdString(temp);
    p_note_text_edit->setText("Note:\n" + note);

    emit noteEdited();
}

void ElementInfoWidget::nameCopyButtonClicked()
{
    QApplication::clipboard()->setText(name);
}

void ElementInfoWidget::passwordCopyButtonClicked()
{
    QApplication::clipboard()->setText(password);
}

void ElementInfoWidget::noteCopyButtonClicked()
{
    QApplication::clipboard()->setText(note);
}

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

    p_name_label = new QLabel;
    p_password_label = new QLabel;
    p_note_label = new QLabel;

    //placement
    setLayout(p_central_vertical_layout);

    p_name_horizontal_layout->addWidget(p_name_label);
    p_name_horizontal_layout->addWidget(p_name_copy_button);
    p_name_horizontal_layout->addWidget(p_name_edit_button);

    p_password_horizontal_layout->addWidget(p_password_label);
    p_password_horizontal_layout->addWidget(p_password_copy_button);
    p_password_horizontal_layout->addWidget(p_password_edit_button);

    p_note_horizontal_layout->addWidget(p_note_label);
    p_note_horizontal_layout->addWidget(p_note_copy_button);
    p_note_horizontal_layout->addWidget(p_note_edit_button);

    p_remove_button_horizontal_layout->addWidget(p_remove_button);

    p_central_vertical_layout->addLayout(p_name_horizontal_layout);
    p_central_vertical_layout->addLayout(p_password_horizontal_layout);
    p_central_vertical_layout->addLayout(p_note_horizontal_layout);
    p_central_vertical_layout->addLayout(p_remove_button_horizontal_layout);

    p_name_label->setFrameStyle(QFrame::Box);
    p_password_label->setFrameStyle(QFrame::Box);
    p_note_label->setFrameStyle(QFrame::Box);

    //buttons icon settings
    QPixmap copy_pix(":/images/copy200x200.png");
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

    QPixmap remove_pix(":/images/remove200x200.png");
    p_remove_button->setIcon(remove_pix);
    p_remove_button->setIconSize(QSize(90, 90));

    //buttons size settings
    p_name_copy_button->setFixedSize(QSize(40, 40));
    p_password_copy_button->setFixedSize(QSize(40, 40));
    p_note_copy_button->setFixedSize(QSize(40, 40));

    p_name_edit_button->setFixedSize(QSize(40, 40));
    p_password_edit_button->setFixedSize(QSize(40, 40));
    p_note_edit_button->setFixedSize(QSize(40, 40));

    p_remove_button->setFixedSize(QSize(80, 80));

    //buttons flat settings
    p_name_copy_button->setFlat(true);
    p_password_copy_button->setFlat(true);
    p_note_copy_button->setFlat(true);

    p_name_edit_button->setFlat(true);
    p_password_edit_button->setFlat(true);
    p_note_edit_button->setFlat(true);

    p_remove_button->setFlat(true);

    //labels settings
    p_name_label->setFrameStyle(QFrame::Box);
    p_password_label->setFrameStyle(QFrame::Box);
    p_note_label->setFrameStyle(QFrame::Box);

    p_name_label->setFixedSize(300, 70);
    p_password_label->setFixedSize(300, 70);
    p_note_label->setFixedSize(300, 120);

    p_note_label->setAlignment(Qt::AlignTop);

    p_name_label->setFont(QFont("phosphate", 20));
    p_password_label->setFont(QFont("phosphate", 20));
    p_note_label->setFont(QFont("phosphate", 20));

    //connections
    connect(p_name_copy_button, SIGNAL(clicked(bool)), SLOT(nameCopyButtonClicked()));
    connect(p_password_copy_button, SIGNAL(clicked(bool)), SLOT(passwordCopyButtonClicked()));
    connect(p_note_copy_button, SIGNAL(clicked(bool)), SLOT(noteCopyButtonClicked()));

    connect(p_name_edit_button, SIGNAL(clicked(bool)), SIGNAL(nameEditButtonClicked()));
    connect(p_password_edit_button, SIGNAL(clicked(bool)), SIGNAL(passwordEditButtonClicked()));
    connect(p_note_edit_button, SIGNAL(clicked(bool)), SIGNAL(noteEditButtonClicked()));

    connect(p_remove_button, SIGNAL(clicked(bool)), SIGNAL(removeButtonClicked()));
}

ElementInfoWidget::~ElementInfoWidget()
{
    delete p_pair_button;
}

void ElementInfoWidget::setPairButton(ElementButton *p_button)
{
    p_pair_button = p_button;
}

void ElementInfoWidget::setName(QString _name)
{
    name = _name;
    p_name_label->setText("Name: " + _name);
    p_pair_button->setText(_name);

    emit nameEdited();
}

void ElementInfoWidget::setPassword(QString _password)
{
    password = _password;
    p_password_label->setText("Password: " + _password);

    emit passwordEdited();
}

void ElementInfoWidget::setNote(QString _note)
{
    note = _note;
    p_note_label->setText("Note: " + _note);

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

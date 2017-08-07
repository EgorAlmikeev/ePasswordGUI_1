#include "elementinfowidget.h"

ElementInfoWidget::ElementInfoWidget(QWidget *parent) : QWidget(parent)
{
    p_central_grid_layout = new QGridLayout;

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


    p_central_grid_layout->addWidget(p_name_label, 0, 0, 1, 1);
    p_central_grid_layout->addWidget(p_name_copy_button, 0, 1, 1, 1);
    p_central_grid_layout->addWidget(p_name_edit_button, 0, 2, 1, 1);

    p_central_grid_layout->addWidget(p_password_label, 1, 0, 1, 1);
    p_central_grid_layout->addWidget(p_password_copy_button, 1, 1, 1, 1);
    p_central_grid_layout->addWidget(p_password_edit_button, 1, 2, 1, 1);

    p_central_grid_layout->addWidget(p_note_label, 2, 0, 2, 1);
    p_central_grid_layout->addWidget(p_note_copy_button, 2, 1, 1, 1);
    p_central_grid_layout->addWidget(p_note_edit_button, 2, 2, 1, 1);

    p_central_grid_layout->addWidget(p_remove_button, 4, 1, 1, 1);


    QPixmap copy_pix(":/images/copy200x200.png");
    p_name_copy_button->setIcon(copy_pix);
    p_password_copy_button->setIcon(copy_pix);
    p_note_copy_button->setIcon(copy_pix);

    QPixmap edit_pix(":/images/edit.png");
    p_name_edit_button->setIcon(edit_pix);
    p_password_edit_button->setIcon(edit_pix);
    p_note_edit_button->setIcon(edit_pix);

    QPixmap remove_pix(":/images/remove200x200.png");
    p_remove_button->setIcon(remove_pix);
}

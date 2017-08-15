#include "mainwindow.h"
#include "elementbutton.h"
#include "elementinfowidget.h"
#include "userpasswordinput.h"
#include "usernameinput.h"
#include "usernoteinput.h"

#include <QLabel>
#include <QPushButton>
#include <QScrollArea>
#include <QVBoxLayout>
#include <QStackedWidget>
#include <QGridLayout>
#include <QDebug>

#include <QtAlgorithms>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    p_central_widget = new QLabel;
    p_grid_layout = new QGridLayout;

    p_add_button = new QPushButton;
    p_wipe_button = new QPushButton;

    p_stacked_info_widget = new QStackedWidget;

    p_scroll_area = new QScrollArea;
    p_scroll_area_widget = new QWidget;
    p_scroll_area_widget_layout = new QVBoxLayout;

    p_logo_widget = new QLabel;
    p_author_button = new QPushButton;

    scroll_widget_height = 0;
    element_buttons_height = 70;

    setCentralWidget(p_central_widget);
    p_central_widget->setLayout(p_grid_layout);

    p_scroll_area->setWidget(p_scroll_area_widget);
    p_scroll_area_widget->setLayout(p_scroll_area_widget_layout);


    createObjectNames();
    createWidgetsPlacement();

    createButtonsSettings();
    createScrollAreaSettings();

    createBackGround();
    createLogoWidgetSettings();

    createTakeNameInputWidget();
    createTakePasswordInputWidget();
    createTakeNoteInputWidget();
}

MainWindow::~MainWindow()
{}

void MainWindow::createWidgetsPlacement()
{
    p_grid_layout->addWidget(p_add_button, 0, 0, 1, 1);
    p_grid_layout->addWidget(p_wipe_button, 0, 1, 1, 1);

    p_grid_layout->addWidget(p_logo_widget, 0, 2, 1, 1);
    p_grid_layout->addWidget(p_author_button, 0, 3, 1, 1);

    p_grid_layout->addWidget(p_scroll_area, 1, 0, 1, 2);
    p_grid_layout->addWidget(p_stacked_info_widget, 1, 2, 1, 2);
}

void MainWindow::createButtonsSettings()
{
    //add button
    QPixmap add_pix(":/images/add150x72.png");

    p_add_button->setIcon(add_pix);
    p_add_button->setIconSize(add_pix.size());
    p_add_button->setMaximumHeight(add_pix.height());
    p_add_button->setMaximumWidth(add_pix.width());

    p_add_button->setFlat(true);
    p_add_button->setToolTip("Add new data");

    connect(p_add_button, SIGNAL(clicked(bool)), SLOT(processTakeName()));
    connect(p_add_button, SIGNAL(clicked(bool)), SLOT(startInput()));

    //wipe button
    QPixmap wipe_pix(":/images/wipe_data69x72.png");

    p_wipe_button->setIcon(wipe_pix);
    p_wipe_button->setIconSize(wipe_pix.size());
    p_wipe_button->setMaximumHeight(wipe_pix.height());
    p_wipe_button->setMaximumWidth(wipe_pix.width());

    p_wipe_button->setFlat(true);
    p_wipe_button->setToolTip("Wipe all saves");

    connect(p_wipe_button, SIGNAL(clicked(bool)), SLOT(processWipeData()));

    //author button
    p_author_button->setText("About author");
    p_author_button->setFont(QFont("phosphate", 15));
    p_author_button->setFlat(true);
    p_author_button->setFixedWidth(110);

    connect(p_author_button, SIGNAL(clicked(bool)), SLOT(showAuthorWidget()));
}

void MainWindow::createObjectNames()
{
    p_central_widget->setObjectName("central widget");
    p_grid_layout->setObjectName("grid");

    p_add_button->setObjectName("add button");
    p_wipe_button->setObjectName("wipe_button");

    p_stacked_info_widget->setObjectName("stacked widget");

    p_scroll_area->setObjectName("scroll area");
    p_scroll_area_widget->setObjectName("scroll widget");
    p_scroll_area_widget_layout->setObjectName("scroll layout");

    p_logo_widget->setObjectName("logo");
    p_author_button->setObjectName("author button");
}

void MainWindow::createScrollAreaSettings()
{
    QBrush scroll_area_brush;
    QPalette scroll_area_palette;

    scroll_area_brush.setTexture(QPixmap(":/images/wood.jpg"));
    scroll_area_palette.setBrush(p_scroll_area->backgroundRole(), scroll_area_brush);

    p_scroll_area->setPalette(scroll_area_palette);

    p_scroll_area_widget_layout->setMargin(0);
    p_scroll_area_widget_layout->setSpacing(0);
}

void MainWindow::createBackGround()
{
    p_central_widget->setPixmap(QPixmap(":/images/background.jpg"));
}

void MainWindow::createTakeNameInputWidget()
{
    p_name_input = new UserNameInput;

    p_name_input->setNameMaximumLength(20);
    p_name_input->setNameMinimumLength(5);
    p_name_input->setText("name settings");

    p_stacked_info_widget->addWidget(p_name_input);

    connect(p_name_input, SIGNAL(sendName(QString)), SLOT(copyToNameBuffer(QString)));
    connect(p_name_input, SIGNAL(sendName(QString)), SLOT(finishInput()));
}

void MainWindow::createTakePasswordInputWidget()
{
    p_password_input = new UserPasswordInput;

    p_password_input->setPasswordMaximumLength(20);
    p_password_input->setPasswordMinimumLength(5);
    p_password_input->setText("password settings");

    p_stacked_info_widget->addWidget(p_password_input);

    connect(p_password_input, SIGNAL(sendPassword(QString)), SLOT(copyToPasswordBuffer(QString)));
    connect(p_password_input, SIGNAL(sendPassword(QString)), SLOT(finishInput()));
}

void MainWindow::createTakeNoteInputWidget()
{
    p_note_input = new UserNoteInput;

    p_note_input->setText("note settings");

    p_stacked_info_widget->addWidget(p_note_input);

    connect(p_note_input, SIGNAL(sendNote(QString)), SLOT(copyToNoteBuffer(QString)));
    connect(p_note_input, SIGNAL(sendNote(QString)), SLOT(finishInput()));
}

void MainWindow::clearInputWidgets()
{
    p_name_input->clearInput();
    p_password_input->clearInput();
    p_note_input->clearInput();
}

void MainWindow::createAuthorWidgetSettings()
{
    QLabel *p_about_label = new QLabel(
                "Hi! My name is York.\n"
                "I'm from Saint-Petersburg (Russia).\n\n"
                "I really hope you will use my password\n"
                "manager with fun.\n\n"
                "If you wanna connect with me,\n"
                "so use this e-mail : york.git@gmail.com\n\n"
                "This is an open-source application,\n"
                "so I can send you all the sources.\n\n"
                "Thanks for using my application,\n"
                "good luck!"
                );
    p_about_label->setSizePolicy(QSizePolicy::Maximum, QSizePolicy::Maximum);
    p_about_label->setFont(QFont("phosphate", 20));
    p_about_label->setAlignment(Qt::AlignCenter);

    p_stacked_info_widget->addWidget(p_author_widget);

    QPushButton *p_close_button = new QPushButton("close");

    QVBoxLayout *p_about_layout = new QVBoxLayout;
    p_about_layout->addWidget(p_about_label);
    p_about_layout->addWidget(p_close_button);

    p_author_widget->setLayout(p_about_layout);

    connect(p_close_button, SIGNAL(clicked(bool)), p_author_widget, SLOT(close()));
}

void MainWindow::createLogoWidgetSettings()
{
    p_logo_widget->setText("York's Product");
    p_logo_widget->setFont(QFont("phosphate", 35));
    p_logo_widget->setFixedWidth(300);
    p_logo_widget->setAlignment(Qt::AlignCenter);
}

//slots
void MainWindow::processRefreshScrollArea()
{
    qDebug() << "refresh scroll area";

    std::sort(element_buttons_list.begin(), element_buttons_list.end(), element_buttons_compare);

    scroll_widget_height = 0;

    delete p_scroll_area_widget_layout;

    p_scroll_area_widget_layout = new QVBoxLayout;
    p_scroll_area_widget->setLayout(p_scroll_area_widget_layout);

    for(QList<ElementButton*>::iterator iter = element_buttons_list.begin(); iter != element_buttons_list.end(); ++iter)
    {
        p_scroll_area_widget->resize(p_scroll_area->width() - 2, scroll_widget_height += (*iter)->height());
        p_scroll_area_widget_layout->addWidget((*iter));
    }
}

void MainWindow::processCreateNewElement()
{
    qDebug() << "creating new element";
    createNewInfoLabel(name_buffer, password_buffer, note_buffer);
    processRefreshScrollArea();
}

void MainWindow::processRemoveElement()
{}

void MainWindow::processWipeData()
{}

void MainWindow::processTakeName()
{
    qDebug() << "taking name";

    static bool connected = false;

    clearInputWidgets();
    p_name_input->setVisible(true);
    p_stacked_info_widget->setCurrentWidget(p_name_input);

    if(sender() == p_add_button)
    {
        connect(p_name_input, SIGNAL(sendName(QString)), SLOT(processTakePassword()), Qt::UniqueConnection);
        startInput();
    }
    else
    {
        disconnect(p_name_input, SIGNAL(sendName(QString)), this, SLOT(processTakePassword()));
        finishInput();
    }

    if(sender()->objectName() == "info widget")
        connected = connect(p_name_input, SIGNAL(sendName(QString)), sender(), SLOT(setName(QString)), Qt::UniqueConnection);
    else if(connected)
        disconnect(p_name_input, SIGNAL(sendName(QString)), sender(), SLOT(setName(QString)));
}

void MainWindow::processTakePassword()
{
    qDebug() << "taking password";

    static bool connected = false;

    clearInputWidgets();
    p_password_input->setVisible(true);
    p_stacked_info_widget->setCurrentWidget(p_password_input);

    if(sender() == p_name_input)
    {
        connect(p_password_input, SIGNAL(sendPassword(QString)), SLOT(processTakeNote()), Qt::UniqueConnection);
        startInput();
    }
    else
    {
        disconnect(p_password_input, SIGNAL(sendPassword(QString)), this, SLOT(processTakeNote()));
        finishInput();
    }

    if(sender()->objectName() == "info widget")
        connected = connect(p_password_input, SIGNAL(sendPassword(QString)), sender(), SLOT(setPassword(QString)), Qt::UniqueConnection);
    else if(connected)
        disconnect(p_password_input, SIGNAL(sendPassword(QString)), sender(), SLOT(setPassword(QString)));
}

void MainWindow::processTakeNote()
{
    qDebug() << "taking note";

    static bool connected = false;

    clearInputWidgets();
    p_note_input->setVisible(true);
    p_stacked_info_widget->setCurrentWidget(p_note_input);

    if(sender() == p_password_input)
    {
        connect(p_note_input, SIGNAL(sendNote(QString)), SLOT(processCreateNewElement()), Qt::UniqueConnection);
        startInput();
    }
    else
        disconnect(p_note_input, SIGNAL(sendNote(QString)), this, SLOT(processCreateNewElement()));

    if(sender()->objectName() == "info widget")
        connected = connect(p_note_input, SIGNAL(sendNote(QString)), sender(), SLOT(setNote(QString)), Qt::UniqueConnection);
    else if(connected)
        disconnect(p_note_input, SIGNAL(sendNote(QString)), sender(), SLOT(setNote(QString)));
}

void MainWindow::setElementInfoWidget(ElementInfoWidget *p_widget)
{
    qDebug() << "set current widget : " + p_widget->objectName();
    p_stacked_info_widget->setCurrentWidget(p_widget);
}

void MainWindow::showAuthorWidget()
{
    p_author_widget = new QWidget;
    p_author_widget->setObjectName("author widget");
    createAuthorWidgetSettings();
    p_stacked_info_widget->setCurrentWidget(p_author_widget);
}

ElementInfoWidget * MainWindow::createNewInfoLabel(QString name, QString password, QString note)
{
    ElementInfoWidget *p_new_widget = new ElementInfoWidget;

    ElementButton *p_new_button = new ElementButton;

    p_new_widget->setPairButton(p_new_button);
    p_new_button->setPairWidget(p_new_widget);

    p_new_widget->setName(name);
    p_new_widget->setPassword(password);
    p_new_widget->setNote(note);
    p_new_widget->setObjectName("info widget");

    p_stacked_info_widget->addWidget(p_new_widget);
    element_buttons_list << p_new_button;

    connect(p_new_button, SIGNAL(sendPairWidget(ElementInfoWidget*)), SLOT(setElementInfoWidget(ElementInfoWidget*)));

    connect(p_new_widget, SIGNAL(nameEditButtonClicked()), SLOT(processTakeName()));
    connect(p_new_widget, SIGNAL(passwordEditButtonClicked()), SLOT(processTakePassword()));
    connect(p_new_widget, SIGNAL(noteEditButtonClicked()), SLOT(processTakeNote()));

    connect(p_new_widget, SIGNAL(removeButtonClicked()), SLOT(processRemoveElement()));

    return p_new_widget;
}

void MainWindow::copyToNameBuffer(QString string)
{
    name_buffer = string;
}

void MainWindow::copyToPasswordBuffer(QString string)
{
    password_buffer = string;
}

void MainWindow::copyToNoteBuffer(QString string)
{
    note_buffer = string;
}

void MainWindow::setOtherWidgetsEabled(bool boolean)
{
    p_add_button->setEnabled(boolean);
    p_wipe_button->setEnabled(boolean);

    p_scroll_area->setEnabled(boolean);

    p_author_button->setEnabled(boolean);
}

void MainWindow::startInput()
{
    setOtherWidgetsEabled(false);
}

void MainWindow::finishInput()
{
    setOtherWidgetsEabled(true);
}

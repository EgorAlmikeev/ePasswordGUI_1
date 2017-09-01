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
#include <QMessageBox>


ePasswordCore MainWindow::core;
int MainWindow::element_buttons_height = 50;

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

    p_author_button = new QPushButton;

    p_null_widget = new QLabel;
    p_stacked_info_widget->addWidget(p_null_widget);

    scroll_widget_height = 0;

    setCentralWidget(p_central_widget);
    p_central_widget->setLayout(p_grid_layout);

    p_scroll_area->setWidget(p_scroll_area_widget);
    p_scroll_area_widget->setLayout(p_scroll_area_widget_layout);


    createObjectNames();
    createWidgetsPlacement();

    createButtonsSettings();
    createScrollAreaSettings();

    createBackGround();

    createTakeNameInputWidget();
    createTakePasswordInputWidget();
    createTakeNoteInputWidget();

    if(!core.elements.empty())
        processReadElementsFromFile();

    clearElementInfoWidget();
}

MainWindow::~MainWindow()
{}

void MainWindow::createWidgetsPlacement()
{
    QHBoxLayout *p_add_wipe_layout = new QHBoxLayout;

    p_add_wipe_layout->setSpacing(0);
    p_add_wipe_layout->setMargin(10);
    p_add_wipe_layout->setAlignment(Qt::AlignCenter);

    p_add_wipe_layout->addWidget(p_add_button);
    p_add_wipe_layout->addWidget(p_wipe_button);

    p_grid_layout->addLayout(p_add_wipe_layout, 0, 0, 1, 2);

    p_grid_layout->addWidget(p_author_button, 0, 2, 1, 2);

    p_grid_layout->addWidget(p_scroll_area, 1, 0, 1, 2);
    p_grid_layout->addWidget(p_stacked_info_widget, 1, 2, 1, 2);
}

void MainWindow::createButtonsSettings()
{
    //add button
    QPixmap add_pix(":/images/add.png");

    p_add_button->setIcon(add_pix);
    p_add_button->setIconSize(add_pix.size() / 2.5);
    p_add_button->setFixedSize(add_pix.size() / 2.5);

    p_add_button->setFlat(true);
    p_add_button->setToolTip("Add new data");

    connect(p_add_button, SIGNAL(clicked(bool)), SLOT(processTakeName()));
//    connect(p_add_button, SIGNAL(clicked(bool)), SLOT(lockOtherWidgets()));

    //wipe button
    QPixmap wipe_pix(":/images/removeall.png");

    p_wipe_button->setIcon(wipe_pix);
    p_wipe_button->setIconSize(wipe_pix.size() / 2.5);
    p_wipe_button->setFixedSize(wipe_pix.size() / 2.5);

    p_wipe_button->setFlat(true);
    p_wipe_button->setToolTip("Remove all saves forever");

    connect(p_wipe_button, SIGNAL(clicked(bool)), SLOT(processWipeData()));

    //author button
    p_author_button->setText("York's product");
    p_author_button->setFont(QFont("phosphate", 35));
    p_author_button->setFlat(true);
    p_author_button->setFixedWidth(450);
    p_author_button->setStyleSheet("color : #591a57;");

    connect(p_author_button, SIGNAL(clicked(bool)), SLOT(showAuthorWidget()));

    p_add_button->setCursor(Qt::OpenHandCursor);
    p_wipe_button->setCursor(Qt::OpenHandCursor);

    p_author_button->setCursor(Qt::OpenHandCursor);

    p_author_button->setToolTip("Information about author");
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

    p_author_button->setObjectName("author button");
}

void MainWindow::createScrollAreaSettings()
{
    p_scroll_area_widget_layout->setMargin(0);
    p_scroll_area_widget_layout->setSpacing(0);
    p_scroll_area->setFixedWidth(230);
    p_scroll_area->setStyleSheet("background-color: rgba(255, 255, 255, 0);");
    p_scroll_area->setFrameStyle(QFrame::Panel);
}

void MainWindow::createBackGround()
{
    p_central_widget->setPixmap(QPixmap(":/images/bg2.jpg"));
}

void MainWindow::createTakeNameInputWidget()
{
    p_name_input = new UserNameInput;

    p_name_input->setNameMaximumLength(20);
    p_name_input->setNameMinimumLength(1);
    p_name_input->setText("name settings");

    p_stacked_info_widget->addWidget(p_name_input);

    connect(p_name_input, SIGNAL(sendName(QString)), SLOT(copyToNameBuffer(QString)));
    connect(p_name_input, SIGNAL(sendName(QString)), SLOT(unlockOtherWidgets()));
}

void MainWindow::createTakePasswordInputWidget()
{
    p_password_input = new UserPasswordInput;

    p_password_input->setPasswordMaximumLength(20);
    p_password_input->setPasswordMinimumLength(5);
    p_password_input->setText("password settings");

    p_stacked_info_widget->addWidget(p_password_input);

    connect(p_password_input, SIGNAL(sendPassword(QString)), SLOT(copyToPasswordBuffer(QString)));
    connect(p_password_input, SIGNAL(sendPassword(QString)), SLOT(unlockOtherWidgets()));
}

void MainWindow::createTakeNoteInputWidget()
{
    p_note_input = new UserNoteInput;

    p_note_input->setText("note settings");

    p_stacked_info_widget->addWidget(p_note_input);

    connect(p_note_input, SIGNAL(sendNote(QString)), SLOT(copyToNoteBuffer(QString)));
    connect(p_note_input, SIGNAL(sendNote(QString)), SLOT(unlockOtherWidgets()));
}

void MainWindow::clearInputWidgets()
{
    p_name_input->clearInput();
    p_password_input->clearInput();
    p_note_input->clearInput();
}

void MainWindow::createAuthorWidgetSettings()
{
    QTextEdit *p_about_text = new QTextEdit;

    p_about_text->setText("Hi! My name is York.\n"
                           "I'm from Saint-Petersburg (Russia).\n\n"
                           "I really hope you will use my\npassword-"
                           "manager with fun.\n\n"
                           "If you wanna connect with me,\n"
                           "use this e-mail : york.git@gmail.com\n\n"
                           "This is an open-source application,\n"
                           "so I can send you all the sources.\n\n"
                           "Thanks for using my application,\n"
                           "good luck!"
                           );

    p_about_text->setAlignment(Qt::AlignCenter);
    p_about_text->setFont(QFont("Courier", 17));
    p_about_text->setReadOnly(true);
    p_about_text->setStyleSheet("background-color : rgba(255, 255, 255, 0)");

    p_stacked_info_widget->addWidget(p_author_widget);

    QPushButton *p_close_button = new QPushButton("close");

    QVBoxLayout *p_about_layout = new QVBoxLayout;
    p_about_layout->addSpacing(20);
    p_about_layout->addWidget(p_about_text);
    p_about_layout->addWidget(p_close_button);

    p_author_widget->setLayout(p_about_layout);

    connect(p_close_button, SIGNAL(clicked(bool)), p_author_widget, SLOT(close()));
    connect(p_close_button, SIGNAL(clicked(bool)), SLOT(clearElementInfoWidget()));

    p_close_button->setCursor(Qt::OpenHandCursor);
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
        p_scroll_area_widget->resize(p_scroll_area->width() - 2, scroll_widget_height += element_buttons_height + 15);
        p_scroll_area_widget_layout->addWidget((*iter));
    }
}

void MainWindow::processCreateNewElement(QString name, QString password, QString note)
{
    qDebug() << "creating new element";

    if(name == 0 && password == 0 && note == 0)
    {
        name = name_buffer;
        password = password_buffer;
        note = note_buffer;

        core.addElement(name, password, note);
        core.writeFile();

        setElementInfoWidget(createNewInfoLabel(name, password, note));
        processRefreshScrollArea();
    }
    else
        createNewInfoLabel(name, password, note);
}

void MainWindow::processRemoveElement()
{
    removeElement((ElementInfoWidget*) sender());
}

void MainWindow::removeElement(ElementInfoWidget *p_widget)
{
    for(QList<ElementButton*>::iterator iter = element_buttons_list.begin(); iter != element_buttons_list.end(); ++iter)
        if(*iter == p_widget->p_pair_button)
        {
            element_buttons_list.erase(iter);
            delete p_widget->p_pair_button;
            break;
        }

    core.removeElement(sender()->objectName());
    core.writeFile();
    delete sender();
    processRefreshScrollArea();
    clearElementInfoWidget();
}

void MainWindow::processWipeData()
{
    QMessageBox *p_wipe_alert = new QMessageBox;

    p_wipe_alert->setText("All data will be deleted.\nAre you sure?");
    p_wipe_alert->setIcon(QMessageBox::Information);
    p_wipe_alert->setInformativeText("Wipe all data?");
    p_wipe_alert->setStandardButtons(QMessageBox::Yes | QMessageBox::No);
    p_wipe_alert->setDefaultButton(QMessageBox::Yes);

    short result = p_wipe_alert->exec();

    if(result == QMessageBox::Yes)
    {

        ElementButton *p_temp_button;

        for(QList<ElementButton*>::iterator iter = element_buttons_list.begin(); iter != element_buttons_list.end(); ++iter)
        {
            p_temp_button = *iter;
            element_buttons_list.erase(iter);
            core.removeElement(p_temp_button->p_pair_widget->objectName());
            delete p_temp_button->p_pair_widget;
            delete p_temp_button;
        }

        core.writeFile();
        clearElementInfoWidget();
        processRefreshScrollArea();
    }
    else;

    delete p_wipe_alert;
}

void MainWindow::processTakeName()
{
    qDebug() << "taking name";

    clearInputWidgets();
    p_name_input->setVisible(true);
    p_stacked_info_widget->setCurrentWidget(p_name_input);

    if(sender() == p_add_button)
    {
        connect(p_name_input, SIGNAL(sendName(QString)), SLOT(processTakePassword()), Qt::UniqueConnection);
//        lockOtherWidgets();
    }
    else
    {
        disconnect(p_name_input, SIGNAL(sendName(QString)), this, SLOT(processTakePassword()));
//        unlockOtherWidgets();
    }
}

void MainWindow::processTakePassword()
{
    qDebug() << "taking password";

    clearInputWidgets();
    p_password_input->setVisible(true);
    p_stacked_info_widget->setCurrentWidget(p_password_input);

    if(sender() == p_name_input)
    {
        connect(p_password_input, SIGNAL(sendPassword(QString)), SLOT(processTakeNote()), Qt::UniqueConnection);
//        lockOtherWidgets();
    }
    else
    {
        disconnect(p_password_input, SIGNAL(sendPassword(QString)), this, SLOT(processTakeNote()));
//        unlockOtherWidgets();
    }
}

void MainWindow::processTakeNote()
{
    qDebug() << "taking note";

    clearInputWidgets();
    p_note_input->setVisible(true);
    p_stacked_info_widget->setCurrentWidget(p_note_input);

    if(sender() == p_password_input)
    {
        connect(p_note_input, SIGNAL(sendNote(QString)), SLOT(processCreateNewElement()), Qt::UniqueConnection);
//        lockOtherWidgets();
    }
    else
        disconnect(p_note_input, SIGNAL(sendNote(QString)), this, SLOT(processCreateNewElement()));
}

void MainWindow::createEditConnections()
{
    ElementInfoWidget *p_sender = (ElementInfoWidget*) sender();

    //name
    connect(p_name_input, SIGNAL(sendName(QString)), sender(), SLOT(setName(QString)), Qt::UniqueConnection);
    connect(p_name_input, SIGNAL(sendName(QString)), SLOT(processRefreshScrollArea()), Qt::UniqueConnection);
    //password
    connect(p_password_input, SIGNAL(sendPassword(QString)), sender(), SLOT(setPassword(QString)), Qt::UniqueConnection);
    //note
    connect(p_note_input, SIGNAL(sendNote(QString)), sender(), SLOT(setNote(QString)), Qt::UniqueConnection);

    connect(p_name_input, SIGNAL(sendName(QString)), SLOT(destroyEditConnections()), Qt::UniqueConnection);
    connect(p_password_input, SIGNAL(sendPassword(QString)), SLOT(destroyEditConnections()), Qt::UniqueConnection);
    connect(p_note_input, SIGNAL(sendNote(QString)), SLOT(destroyEditConnections()), Qt::UniqueConnection);

    p_name_input->p_line_edit->setText(p_sender->name);
    p_name_input->checkText();
    p_password_input->p_line_edit->setText(p_sender->password);
    p_note_input->p_text_edit->setText(p_sender->note);

    p_name_input->p_next_button->setText("Ok");
    p_password_input->p_next_button->setText("Ok");
    p_note_input->p_next_button->setText("Ok");
}

void MainWindow::destroyEditConnections()
{
    ElementInfoWidget *p_sender = (ElementInfoWidget*) sender();

    //name
    disconnect(p_name_input, SIGNAL(sendName(QString)), sender(), SLOT(setName(QString)));
    //password
    disconnect(p_password_input, SIGNAL(sendPassword(QString)), sender(), SLOT(setPassword(QString)));
    //note
    disconnect(p_note_input, SIGNAL(sendNote(QString)), sender(), SLOT(setNote(QString)));

    disconnect(p_name_input, SIGNAL(sendName(QString)), this, SLOT(destroyEditConnections()));
    disconnect(p_password_input, SIGNAL(sendPassword(QString)), this, SLOT(destroyEditConnections()));
    disconnect(p_note_input, SIGNAL(sendNote(QString)), this, SLOT(destroyEditConnections()));

    processElementEdited(p_sender);
    clearInputWidgets();
    p_name_input->p_next_button->setText("Next");
    p_password_input->p_next_button->setText("Next");
    p_note_input->p_next_button->setText("Next");
}

void MainWindow::processElementEdited(ElementInfoWidget *p_widget)
{
    qDebug() << "element edited : " << p_widget->objectName();

    QString name, password, note;

    name = p_widget->name;
    password = p_widget->password;
    note = p_widget->note;

    removeElement(p_widget);

    core.addElement(name, password, note);
    core.writeFile();

    setElementInfoWidget(createNewInfoLabel(name, password, note));
    processRefreshScrollArea();
}

void MainWindow::clearElementInfoWidget()
{
    p_stacked_info_widget->setCurrentWidget(p_null_widget);
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
    p_new_widget->setObjectName(name);

    p_stacked_info_widget->addWidget(p_new_widget);
    element_buttons_list << p_new_button;

    connect(p_new_button, SIGNAL(sendPairWidget(ElementInfoWidget*)), SLOT(setElementInfoWidget(ElementInfoWidget*)));

    connect(p_new_widget, SIGNAL(nameEditButtonClicked()), SLOT(processTakeName()));
    connect(p_new_widget, SIGNAL(nameEditButtonClicked()), SLOT(createEditConnections()));

    connect(p_new_widget, SIGNAL(passwordEditButtonClicked()), SLOT(processTakePassword()));
    connect(p_new_widget, SIGNAL(passwordEditButtonClicked()), SLOT(createEditConnections()));

    connect(p_new_widget, SIGNAL(noteEditButtonClicked()), SLOT(processTakeNote()));
    connect(p_new_widget, SIGNAL(noteEditButtonClicked()), SLOT(createEditConnections()));

    connect(p_new_widget, SIGNAL(nameEdited()), SLOT(destroyEditConnections()));
    connect(p_new_widget, SIGNAL(passwordEdited()), SLOT(destroyEditConnections()));
    connect(p_new_widget, SIGNAL(noteEdited()), SLOT(destroyEditConnections()));


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

void MainWindow::lockOtherWidgets()
{
    setOtherWidgetsEabled(false);
}

void MainWindow::unlockOtherWidgets()
{
    setOtherWidgetsEabled(true);
}

void MainWindow::processReadElementsFromFile()
{
    QString name, password, note;

    core.readFile();

    for(core.iter = core.elements.begin(); core.iter != core.elements.end();)
    {
        name = core.iter.value();
        core.iter++;
        password = core.iter.value();
        core.iter++;
        note = core.iter.value();
        core.iter++;

        processCreateNewElement(name, password, note);
    }
}

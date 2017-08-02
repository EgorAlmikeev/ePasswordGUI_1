#include "mainwindow.h"
#include "elementbutton.h"
#include "elementinfowidget.h"
#include "userpasswordinput.h"
#include "usertextinput.h"

#include <QLabel>
#include <QPushButton>
#include <QScrollArea>
#include <QVBoxLayout>
#include <QStackedWidget>
#include <QGridLayout>

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

    setCentralWidget(p_central_widget);
    p_central_widget->setLayout(p_grid_layout);

    p_scroll_area->setWidget(p_scroll_area_widget);
    p_scroll_area_widget->setLayout(p_scroll_area_widget_layout);


    createWidgetsPlacement();
    createButtonsSettings();
    createScrollAreaSettings();
    createBackGround();
    createLogoWidgetSettings();
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

    connect(p_add_button, SIGNAL(clicked(bool)), SLOT(processAddNewElement()));

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

void MainWindow::createScrollAreaSettings()
{
    QBrush scroll_area_brush;
    QPalette scroll_area_palette;

    scroll_area_brush.setTexture(QPixmap(":/images/wood.jpg"));
    scroll_area_palette.setBrush(p_scroll_area->backgroundRole(), scroll_area_brush);

    p_scroll_area->setPalette(scroll_area_palette);
}

void MainWindow::createBackGround()
{
    p_central_widget->setPixmap(QPixmap(":/images/framewood700x523.jpg"));
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
void MainWindow::processAddNewElement()
{}

void MainWindow::processRemoveElement()
{}

void MainWindow::processWipeData()
{}

void MainWindow::processTakeDataFromUser()
{}

void MainWindow::setElementInfo(QWidget *)
{}

void MainWindow::showAuthorWidget()
{
    p_author_widget = new QWidget;
    createAuthorWidgetSettings();
    p_stacked_info_widget->setCurrentWidget(p_author_widget);
}

ElementInfoWidget * MainWindow::createNewInfoLabel(QString *name, QString *password, QString *note)
{}

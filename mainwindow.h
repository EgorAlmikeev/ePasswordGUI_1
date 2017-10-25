#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <epasswordcore.h>

class QLabel;
class QGridLayout;
class QPushButton;
class QScrollArea;
class QVBoxLayout;
class QStackedWidget;

class ElementButton;
class ElementInfoWidget;
class UserNameInput;
class UserPasswordInput;
class UserNoteInput;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

    static ePasswordCore core;

private :

    QLabel *p_central_widget;
    QGridLayout *p_grid_layout;

    QPushButton *p_add_button;
    QPushButton *p_wipe_button;

    QStackedWidget *p_stacked_info_widget;

    QScrollArea *p_scroll_area;
    QWidget *p_scroll_area_widget;
    QVBoxLayout *p_scroll_area_widget_layout;

    QWidget *p_author_widget;
    QPushButton *p_author_button;

    QList<ElementButton*> element_buttons_list;

    QLabel *p_null_widget;

    int scroll_widget_height;

    public :

    static int element_buttons_height;

private :

    void createButtonsSettings();
    void createScrollAreaSettings();
    void createTakeNameInputWidget();
    void createTakePasswordInputWidget();
    void createTakeNoteInputWidget();

    void clearInput();

    void createWidgetsPlacement();
    void createBackGround();
    void createObjectNames();

    void createAuthorWidgetSettings();

    ElementInfoWidget * createNewInfoLabel(QString name, QString password, QString note);

    void removeElement(ElementInfoWidget*);

    QString name_buffer,
            password_buffer,
            note_buffer;

    UserNameInput *p_name_input;
    UserPasswordInput *p_password_input;
    UserNoteInput *p_note_input;

signals:

    void nextInput();

public slots:

    void processRefreshScrollArea();
    void processCreateNewElement(QString name = 0, QString password = 0, QString note = 0);
    void processRemoveElement();
    void processWipeData();

    void processReadElementsFromFile();

    void processElementEdited(ElementInfoWidget*);

    void processTakeName();
    void processTakePassword();
    void processTakeNote();

    void createEditConnections();
    void destroyEditConnections();

    void clearElementInfoWidget();

    void setElementInfoWidget(ElementInfoWidget*);
    void showAuthorWidget();

    void copyToNameBuffer(QString);
    void copyToPasswordBuffer(QString);
    void copyToNoteBuffer(QString);

    void setOtherWidgetsEabled(bool);

    void lockOtherWidgets();
    void unlockOtherWidgets();
};

#endif // MAINWINDOW_H

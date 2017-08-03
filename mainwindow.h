#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

class QLabel;
class QGridLayout;
class QPushButton;
class QScrollArea;
class QVBoxLayout;
class QStackedWidget;

class ElementButton;
class ElementInfoWidget;
class UserPasswordInput;
class UserTextInput;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

    QLabel *p_central_widget;
    QGridLayout *p_grid_layout;

    QPushButton *p_add_button;
    QPushButton *p_wipe_button;

    QStackedWidget *p_stacked_info_widget;

    QScrollArea *p_scroll_area;
    QWidget *p_scroll_area_widget;
    QVBoxLayout *p_scroll_area_widget_layout;

    QLabel *p_logo_widget;
    QWidget *p_author_widget;
    QPushButton *p_author_button;

    int scroll_widget_height;
    int element_buttons_height;

    void createWidgetsPlacement();
    void createButtonsSettings();
    void createScrollAreaSettings();
    void createBackGround();
    void createLogoWidgetSettings();
    void createObjectNames();

    void createAuthorWidgetSettings();

    QString name_buffer,
            password_buffer,
            note_buffer;

signals:

    void nextInput();

public slots:

    void processCreateNewElement();
    void processRemoveElement();
    void processWipeData();

    void processTakeName();
    void processTakePassword();
    void processTakeNote();

    ElementInfoWidget * createNewInfoLabel(QString *name, QString *password, QString *note);

    void setElementInfo(QWidget*);
    void showAuthorWidget();

    void copyToNameBuffer(QString);
    void copyToPasswordBuffer(QString);
    void copyToNoteBuffer(QString);
};

#endif // MAINWINDOW_H

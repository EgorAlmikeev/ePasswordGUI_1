#ifndef ELEMENTINFOWIDGET_H
#define ELEMENTINFOWIDGET_H

#include <QWidget>
#include <QBoxLayout>
#include <QPushButton>
#include <QLabel>
#include <QApplication>
#include <QClipboard>
#include <QLineEdit>
#include <QTextEdit>

class ElementButton;

class ElementInfoWidget : public QWidget
{
    Q_OBJECT
public:
    explicit ElementInfoWidget(QWidget *parent = nullptr);

private:

    QBoxLayout *p_central_vertical_layout;

    QBoxLayout *p_name_horizontal_layout;
    QBoxLayout *p_password_horizontal_layout;
    QBoxLayout *p_note_horizontal_layout;
    QBoxLayout *p_remove_button_horizontal_layout;

    QPushButton *p_name_copy_button;
    QPushButton *p_name_edit_button;

    QPushButton *p_password_copy_button;
    QPushButton *p_password_edit_button;

    QPushButton *p_note_copy_button;
    QPushButton *p_note_edit_button;

    QPushButton *p_remove_button;

    QLabel *p_name_label;
    QLabel *p_password_label;
    QLabel *p_note_label;


public:

    ElementButton *p_pair_button;
    QString name, password, note;

signals:

    void removeButtonClicked();

    void nameEditButtonClicked();
    void passwordEditButtonClicked();
    void noteEditButtonClicked();

    void nameEdited();
    void passwordEdited();
    void noteEdited();

public slots:

    void setPairButton(ElementButton*);

    void setName(QString);
    void setPassword(QString);
    void setNote(QString);

private slots:

    void nameCopyButtonClicked();
    void passwordCopyButtonClicked();
    void noteCopyButtonClicked();
};

#endif // ELEMENTINFOWIDGET_H

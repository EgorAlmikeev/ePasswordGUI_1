#ifndef ELEMENTINFOWIDGET_H
#define ELEMENTINFOWIDGET_H

#include <QWidget>
#include <QGridLayout>
#include <QPushButton>
#include <QLabel>
#include <QApplication>
#include <QClipboard>

class ElementButton;

class ElementInfoWidget : public QWidget
{
    Q_OBJECT
public:
    explicit ElementInfoWidget(QWidget *parent = nullptr);

private:

    QGridLayout *p_central_grid_layout;

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

#ifndef ELEMENTINFOWIDGET_H
#define ELEMENTINFOWIDGET_H

#include <QWidget>
#include <QGridLayout>
#include <QPushButton>
#include <QLabel>

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

    ElementButton *p_pair_button;

public:

    QString name, password, note;

signals:

    void removeButtonClicked();

    void sendStringToCopy(QString);

    void nameEditButtonClicked();
    void passwordEditButtonClicked();
    void noteEditButtonClicked();

    void nameCopyButtonClicked();
    void passwordCopyButtonClicked();
    void noteCopyButtonClicked();

public slots:

    void setPairButton(ElementButton*);

    void setName(QString);
    void setPassword(QString);
    void setNote(QString);
};

#endif // ELEMENTINFOWIDGET_H

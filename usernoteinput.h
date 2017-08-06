#ifndef USERNOTEINPUT_H
#define USERNOTEINPUT_H

#include <QWidget>
#include <QLabel>
#include <QTextEdit>
#include <QVBoxLayout>
#include <QPushButton>

class UserNoteInput : public QWidget
{
    Q_OBJECT
public:
    explicit UserNoteInput(QWidget *parent = nullptr);

    QVBoxLayout *p_central_vertical_layout;
    QLabel *p_label;
    QTextEdit *p_text_edit;
    QPushButton *p_next_button;

signals:

    void sendNote(QString);

public slots:

    void nextButtonClicked();
    void setText(QString);

    void clearInput();

};

#endif // USERNOTEINPUT_H

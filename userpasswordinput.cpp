#include "userpasswordinput.h"

UserPasswordInput::UserPasswordInput(QWidget *parent) : QWidget(parent)
{
    p_central_grid_layout = new QGridLayout;
    setLayout(p_central_grid_layout);

    p_generate_button = new QPushButton("Generate");
    p_next_button = new QPushButton("Next");

    p_label = new QLabel;
    p_line_edit = new QLineEdit;

    p_letters_checkbox = new QCheckBox("letters");
    p_digits_checkbox = new QCheckBox("digits");
    p_specials_checkbox = new QCheckBox("specials");
    p_user_input_checkbox = new QCheckBox("user password");

    p_slider = new QSlider;
    p_slider_display = new QLabel("20");
    p_slider_display->setAlignment(Qt::AlignCenter);
    p_slider_display->setStyleSheet("background-color : white;");

    p_slider->setRange(5, 20);
    p_slider->setTickInterval(2);
    p_slider->setTickPosition(QSlider::TicksAbove);
    p_slider->setSingleStep(1);
    p_slider->setStyleSheet("background-color : white;");
    p_slider->setValue(20);


    p_central_grid_layout->addWidget(p_label, 0, 0, 1, 4);
    p_central_grid_layout->addWidget(p_letters_checkbox, 1, 0, 1, 2);
    p_central_grid_layout->addWidget(p_digits_checkbox, 2, 0, 1, 2);
    p_central_grid_layout->addWidget(p_specials_checkbox, 3, 0, 1, 2);
    p_central_grid_layout->addWidget(p_user_input_checkbox, 4, 0, 1, 2);

    p_central_grid_layout->addWidget(p_generate_button, 5, 0, 1, 2);
    p_central_grid_layout->addWidget(p_line_edit, 6, 0, 1, 4);
    p_central_grid_layout->addWidget(p_next_button, 6, 4, 1, 1);

    p_central_grid_layout->addWidget(p_slider, 1, 2, 4, 1);
    p_central_grid_layout->addWidget(p_slider_display, 5, 2, 1, 1);

    p_next_button->setEnabled(false);

    connect(p_generate_button, SIGNAL(clicked(bool)), SLOT(generateButtonClicked()));
    connect(p_line_edit, SIGNAL(textEdited(QString)), SLOT(checkPassword()));
    connect(p_line_edit, SIGNAL(textChanged(QString)), SLOT(checkPassword()));
    connect(p_user_input_checkbox, SIGNAL(toggled(bool)), SLOT(userPasswordCheckBoxToggled()));
    connect(p_next_button, SIGNAL(clicked(bool)), SLOT(nextButtonClicked()));

    connect(p_slider, SIGNAL(sliderMoved(int)), p_slider_display, SLOT(setNum(int)));
    connect(p_slider, SIGNAL(valueChanged(int)), p_slider_display, SLOT(setNum(int)));
    connect(p_slider, SIGNAL(sliderMoved(int)), SLOT(setPasswordMaximumLength(int)));


    p_central_grid_layout->setSpacing(0);
    p_central_grid_layout->setMargin(0);

    p_label->setFont(QFont("phosphate", 35));
    p_label->setAlignment(Qt::AlignCenter);
    p_label->setFixedHeight(60);

    p_line_edit->setFixedHeight(60);
    p_line_edit->setFixedWidth(325);
    p_line_edit->setFont(QFont("Aria;", 25));
    p_line_edit->setFocus();
    p_line_edit->setReadOnly(true);

    p_next_button->setFixedSize(90, 70);

    p_letters_checkbox->setFont(QFont("Arial", 20));
    p_digits_checkbox->setFont(QFont("Arial", 20));
    p_specials_checkbox->setFont(QFont("Arial", 20));
    p_user_input_checkbox->setFont(QFont("Arial", 20));

    p_generate_button->setFixedWidth(p_label->width() / 3);

    p_next_button->setCursor(Qt::OpenHandCursor);
    p_generate_button->setCursor(Qt::OpenHandCursor);
}

void UserPasswordInput::userPasswordCheckBoxToggled()
{
    if(p_user_input_checkbox->isChecked())
    {
        p_generate_button->setEnabled(false);

        p_letters_checkbox->setEnabled(false);
        p_digits_checkbox->setEnabled(false);
        p_specials_checkbox->setEnabled(false);

        p_line_edit->setReadOnly(false);

        p_slider->setEnabled(false);
        p_slider_display->setEnabled(false);

        setPasswordMaximumLength(20);
        p_slider->setValue(20);

        p_line_edit->clear();
    }
    else
    {
        p_generate_button->setEnabled(true);

        p_letters_checkbox->setEnabled(true);
        p_digits_checkbox->setEnabled(true);
        p_specials_checkbox->setEnabled(true);

        p_line_edit->setReadOnly(true);

        p_slider->setEnabled(true);
        p_slider_display->setEnabled(true);

        p_line_edit->clear();
    }
}

void UserPasswordInput::checkPassword()
{
    if(p_line_edit->text().length() >= password_minimum_length && !p_line_edit->text().contains(' '))
    {
        p_next_button->setEnabled(true);
        p_line_edit->setStyleSheet( "color : black;" );
    }
    else
    {
        p_next_button->setEnabled(false);
        p_line_edit->setStyleSheet( "color : red;" );
    }
}

void UserPasswordInput::generateButtonClicked()
{
    if(p_password_simbols != nullptr)
        delete p_password_simbols;

    if(p_letters_checkbox->isChecked() && p_digits_checkbox->isChecked() && p_specials_checkbox->isChecked())
        setPasswordSimbolsDigitsLettersSpecials();
    else if(p_letters_checkbox->isChecked() && p_digits_checkbox->isChecked())
        setPasswordSimbolsDigitsLetters();
    else if(p_letters_checkbox->isChecked() && p_specials_checkbox->isChecked())
        setPasswordSimbolsLettersSpecials();
    else if(p_digits_checkbox->isChecked() && p_specials_checkbox->isChecked())
        setPasswordSimbolsDigitsSpecials();
    else if(p_letters_checkbox->isChecked())
        setPasswordSimbolsLetters();
    else if(p_digits_checkbox->isChecked())
        setPasswordSimbolsDigits();
    else if(p_specials_checkbox->isChecked())
        setPasswordSimbolsSpecials();
    else
    {
        password = "";
        p_password_simbols = nullptr;
    }

    if(p_letters_checkbox->isChecked() || p_digits_checkbox->isChecked() || p_specials_checkbox->isChecked())
        password = QString::fromStdString(generatePassword());
    else
        p_password_simbols = nullptr;
    p_line_edit->setText(password);
}

void UserPasswordInput::nextButtonClicked()
{
    emit sendPassword(p_line_edit->text());
    setVisible(false);
}

void UserPasswordInput::setPasswordMaximumLength(int max)
{
    p_line_edit->setMaxLength(max);
    password_maximum_length = max;
}

void UserPasswordInput::setPasswordMinimumLength(int min)
{
    password_minimum_length = min;
}

void UserPasswordInput::setText(QString string)
{
    p_label->setText(string);
}

void UserPasswordInput::clearInput()
{
    p_line_edit->clear();

    p_letters_checkbox->setChecked(true);
    p_digits_checkbox->setChecked(true);
    p_specials_checkbox->setChecked(true);
    p_user_input_checkbox->setChecked(false);
    p_generate_button->setFocus();
}

//password simbols generation functions
std::string UserPasswordInput::generatePassword()
{
    if(p_password_simbols == nullptr)
        return "";

    std::string password;

    short password_simbols_length = strlen(p_password_simbols);

    srand(time(NULL));

    for(int i = 0; i < password_maximum_length; ++i)
        password += p_password_simbols[rand() % password_simbols_length];

    return password;
}

bool UserPasswordInput::setPasswordSimbolsDigits()
{
    p_password_simbols = new char[11];

    for(int i = 0; i < 10; ++i)
        p_password_simbols[i] = i + 48;

    p_password_simbols[10] = '\0';

    return true;
}
bool UserPasswordInput::setPasswordSimbolsLetters()
{
    p_password_simbols = new char[53];

    for(int i = 0; i < 26; ++i)
        p_password_simbols[i] = i + 65;
    for(int i = 26; i < 52; ++i)
        p_password_simbols[i] = i + 71;

    p_password_simbols[52] = '\0';

    return true;
}
bool UserPasswordInput::setPasswordSimbolsSpecials()
{
    p_password_simbols = new char[16];

    for(int i = 0; i < 15; ++i)
        p_password_simbols[i] = i + 33;

    p_password_simbols[15] = '\0';

    return true;
}
bool UserPasswordInput::setPasswordSimbolsDigitsLetters()
{
    p_password_simbols = new char[63];

    for(int i = 0; i < 26; ++i)
        p_password_simbols[i] = i + 65;
    for(int i = 26; i < 52; ++i)
        p_password_simbols[i] = i + 71;
    for(int i = 52; i < 62; ++i)
        p_password_simbols[i] = i - 4;

    p_password_simbols[62] = '\0';

    return true;
}
bool UserPasswordInput::setPasswordSimbolsDigitsSpecials()
{
    p_password_simbols = new char[26];

    for(int i = 0; i < 25; ++i)
        p_password_simbols[i] = i + 33;

    p_password_simbols[25] = '\0';

    return true;
}
bool UserPasswordInput::setPasswordSimbolsLettersSpecials()
{
    p_password_simbols = new char[68];

    for(int i = 0; i < 26; ++i)
        p_password_simbols[i] = i + 65;
    for(int i = 26; i < 52; ++i)
        p_password_simbols[i] = i + 71;
    for(int i = 52; i < 67; ++i)
        p_password_simbols[i] = i - 19;

    p_password_simbols[67] = '\0';

    return true;
}
bool UserPasswordInput::setPasswordSimbolsDigitsLettersSpecials()
{
    p_password_simbols = new char[78];

    for(int i = 0; i < 26; ++i)
        p_password_simbols[i] = i + 65;
    for(int i = 26; i < 52; ++i)
        p_password_simbols[i] = i + 71;
    for(int i = 52; i < 77; ++i)
        p_password_simbols[i] = i - 19;

    p_password_simbols[77] = '\0';

    return true;
}
//end of password simbols generation functions

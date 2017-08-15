#ifndef PASSWORDDATABASE_H
#define PASSWORDDATABASE_H

#include <QMultiMap>
#include <QString>
#include <QFile>
#include <time.h>
#include <cryptor.h>

class PasswordDataBase
{
protected :

    QFile data_file;
    Cryptor cryptor;
    char *password_simbols = nullptr;
    QMultiMap<QString, QString>::iterator iter;
    QMultiMap<QString, QString> element_multi_map;

    //password simbols generation functions
    void setPasswordSimbolsDigits();
    void setPasswordSimbolsLetters();
    void setPasswordSimbolsSpecials();
    void setPasswordSimbolsDigitsLetters();
    void setPasswordSimbolsDigitsSpecials();
    void setPasswordSimbolsLettersSpecials();
    void setPasswordSimbolsDigitsLettersSpecials();
    //end of password simbols generation functions

    void readToMap();
    void writeFromMap();

    void showMap();
    void showMenu();

    void addElement();
    void showElement();
    void editElement();
    void removeElement();

    void wipeDataFile();

    std::string generatePassword();

    void encryptDataFile();
    void decryptDataFile();

    int getSwitchChoice(int min, int max);

public :

    void start();
    void finish();

    PasswordDataBase();
    ~PasswordDataBase();
};

#endif // PASSWORDDATABASE_H

#ifndef PASSWORDDATABASE_H
#define PASSWORDDATABASE_H

#include <QMultiMap>
#include <QString>
#include <QFile>
#include <time.h>
#include <cryptor.h>

class PasswordDataBase
{
private :

    QFile data_file;
    Cryptor cryptor;

    QMultiMap<QString, QString>::iterator iter;

public :

    QMultiMap<QString, QString> element_multi_map;

    void readToMap();
    void writeFromMap();

public :

    void addElement(QString _name, QString _password, QString _note);
    void removeElement(QString _name);

    void wipeDataFile();

    void encryptDataFile();
    void decryptDataFile();

public :

    void decryptReadEncrypt();
    void decryptWriteEncrypt();

    PasswordDataBase();
    ~PasswordDataBase();
};

#endif // PASSWORDDATABASE_H

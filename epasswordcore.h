#ifndef EPASSWORDCORE_H
#define EPASSWORDCORE_H

#include <QMultiMap>
#include <QFile>
#include <fstream>

#include "cryptor.h"

class ePasswordCore
{
public:
    ePasswordCore();

    Cryptor *p_cryptor;
    QMultiMap<QString, QString> elements;
    QMultiMap<QString, QString>::iterator iter;
    QFile data_file;
    QByteArray buffer;


    void readFile();
    void writeFile();

    void addElement(QString name, QString password, QString note);
    void removeElement(QString name);
};

#endif // EPASSWORDCORE_H

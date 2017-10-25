#include "cryptor.h"
#include <iostream>


using namespace std;

Cryptor::Cryptor()
{
    qDebug() << "cryptor constructor 1";
    data.clear();
}

Cryptor::Cryptor(QString crypt_file_name)
{
    qDebug() << "cryptor constructor 2";
    data.clear();
    setCryptFileName(crypt_file_name);
}

Cryptor::~Cryptor()
{
    qDebug() << "cryptor destructor";
}

Cryptor::CryptorException::CryptorException(QString _what)
{
    qDebug() << "cryptor exception";
    what = _what;
}

void Cryptor::CryptorException::errmsg()
{
    qDebug() << "\n#error [CRYPTOR] : " << what;
}

void Cryptor::setCryptFileName(QString crypt_file_name)
{
    qDebug() << "set crypt file name";
    file.setFileName(crypt_file_name);
}

void Cryptor::encryptFile()
{
    qDebug() << "encrypt file";
    if(!file.exists())
        throw CryptorException("file \"" + file.fileName() + "\" does not exist...");

    if(!file.isOpen())
        file.open(QIODevice::Unbuffered | QIODevice::ReadWrite);

    QByteArray buff;
    buff = file.readAll();

    data.clear();

    QByteArray::iterator buff_iter = buff.end();
    while(buff_iter >= buff.begin())
    {
        if(*buff_iter != '\0')
            data += *buff_iter--;
        else
            buff_iter--;
    }

    buff = data.toBase64();
    data.clear();

    buff_iter = buff.end();
    while(buff_iter >= buff.begin())
    {
        if(*buff_iter != '\0')
            data += *buff_iter--;
        else
            buff_iter--;
    }

    buff = data;

    file.close();
    file.open(QIODevice::ReadWrite | QIODevice::Unbuffered | QIODevice::Truncate);

    file.write(buff);
    file.close();
}

void Cryptor::decryptFile()
{
    qDebug() << "decrypt file";
    if(!file.exists())
        throw CryptorException("file \"" + file.fileName() + "\" does not exist...");

    if(!file.isOpen())
        file.open(QIODevice::Unbuffered | QIODevice::ReadWrite);

    QByteArray buff;
    buff = file.readAll();

    data.clear();

    QByteArray::iterator buff_iter = buff.end();
    while(buff_iter >= buff.begin())
    {
        if(*buff_iter != '\0')
            data += *buff_iter--;
        else
            buff_iter--;
    }

    buff = QByteArray::fromBase64(data);
    data.clear();

    buff_iter = buff.end();
    while(buff_iter >= buff.begin())
    {
        if(*buff_iter != '\0')
            data += *buff_iter--;
        else
            buff_iter--;
    }

    buff = data;

    file.close();
    file.open(QIODevice::ReadWrite | QIODevice::Unbuffered | QIODevice::Truncate);

    file.write(buff);
    file.close();
}

QString Cryptor::getCryptFileName()
{
    qDebug() << "get crypt file name";
    return file.fileName();
}

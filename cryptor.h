#ifndef CRYPTOR_H
#define CRYPTOR_H

#include <QFile>
#include <QString>

class Cryptor
{
    QFile file;
    QByteArray data;

public:

    Cryptor();
    Cryptor(QString crypt_file_name);
    ~Cryptor();

    void setCryptFileName(QString crypt_file_name);

    void encryptFile();
    void decryptFile();

    class CryptorException
    {

        QString what;

    public :

        CryptorException(QString _what);
        void errmsg();
    };
};

#endif // CRYPTOR_H

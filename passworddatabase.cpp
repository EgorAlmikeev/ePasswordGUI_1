#include "passworddatabase.h"
#include <iostream>
#include <iomanip>

using namespace std;

PasswordDataBase::PasswordDataBase()
{
    data_file.setFileName("./saves.bin");

    if(!data_file.exists())
    {
        data_file.open(QIODevice::ReadWrite);
        data_file.close();
    }

    iter = element_multi_map.begin();
    cryptor.setCryptFileName(data_file.fileName());

    decryptReadEncrypt();
}

PasswordDataBase::~PasswordDataBase()
{}
void PasswordDataBase::decryptReadEncrypt()
{
    decryptDataFile();
    readToMap();
    encryptDataFile();
}
void PasswordDataBase::decryptWriteEncrypt()
{
    decryptDataFile();
    writeFromMap();
    encryptDataFile();
}
void PasswordDataBase::decryptDataFile()
{
    cryptor.decryptFile();
}
void PasswordDataBase::encryptDataFile()
{
    cryptor.encryptFile();
}
void PasswordDataBase::readToMap()
{
    element_multi_map.clear();

    if(!data_file.isOpen())
        data_file.open(QIODevice::ReadOnly | QIODevice::Unbuffered);

    while(!data_file.atEnd())
    {
        QString temp_key = data_file.readLine();

        element_multi_map.insertMulti(temp_key, data_file.readLine());
        element_multi_map.insertMulti(temp_key, data_file.readLine());
        element_multi_map.insertMulti(temp_key, data_file.readLine());
    }

    data_file.close();
}
void PasswordDataBase::writeFromMap()
{
    if(!data_file.isOpen())
        data_file.open(QIODevice::WriteOnly | QIODevice::Truncate | QIODevice::Unbuffered);

    QString last_key = NULL;
    QByteArray key_buff, name_buff, note_buff, password_buff;

    for(iter = element_multi_map.begin(); iter != element_multi_map.end(); ++iter)
    {
        if(iter.key() != last_key)
        {
            last_key = iter.key();
            key_buff.append(last_key);
            data_file.write(key_buff);
            key_buff.clear();
        }

        password_buff.append((iter++).value());
        note_buff.append((iter++).value());
        name_buff.append((iter).value());

        data_file.write(name_buff);
        data_file.write(note_buff);
        data_file.write(password_buff);

        name_buff.clear();
        note_buff.clear();
        password_buff.clear();
        key_buff.clear();
    }

    data_file.close();
}

void PasswordDataBase::addElement(QString _name, QString _password, QString _note)
{
    string name, password, note;

    name = _name.toStdString();
    password = _password.toStdString();
    note = _note.toStdString();

    name += "\n";
    note += "\n";
    password += "\n";

    element_multi_map.insertMulti(QString::fromStdString(name), QString::fromStdString(name));
    element_multi_map.insertMulti(QString::fromStdString(name), QString::fromStdString(note));
    element_multi_map.insertMulti(QString::fromStdString(name), QString::fromStdString(password));
}

void PasswordDataBase::removeElement(QString _name)
{
    string name;

    name = _name.toStdString();

    iter = element_multi_map.find(QString::fromStdString(name + '\n'));

    element_multi_map.erase(iter++);
    element_multi_map.erase(iter++);
    element_multi_map.erase(iter++);
}
void PasswordDataBase::wipeDataFile()
{
    element_multi_map.clear();
}

#include "epasswordcore.h"
#include "QDir"

ePasswordCore::ePasswordCore()
{

    data_file.setFileName(QDir::current().absolutePath() + "/ePasswordSaves.txt");
//    p_cryptor = new Cryptor(data_file.fileName());

    if(data_file.exists() && data_file.size() > 0)
        readFile();
    else if(!data_file.exists())
    {
        data_file.open(QFile::WriteOnly);
        data_file.close();
    }
}

void ePasswordCore::readFile()
{
    try
    {
        elements.clear();
        buffer.clear();

//        p_cryptor->decryptFile();

        data_file.open(QFile::ReadOnly);

        QString name, password, note;
        std::string std_temp;

        while(!data_file.atEnd())
        {
            buffer = data_file.readLine();
            name = buffer;

            std_temp = name.toStdString();

            std_temp.erase(std_temp.length() - 1, std_temp.length());

            name = QString::fromStdString(std_temp);

            buffer = data_file.readLine();
            password = buffer;

            std_temp = password.toStdString();

            std_temp.erase(std_temp.length() - 1, std_temp.length());

            password = QString::fromStdString(std_temp);

            buffer = data_file.readLine();
            note = buffer;

            std_temp = note.toStdString();

            std_temp.erase(std_temp.length() - 1, std_temp.length());

            note = QString::fromStdString(std_temp);

            elements.insertMulti(name, note);
            elements.insertMulti(name, password);
            elements.insertMulti(name, name);
        }
    }
    catch(std::out_of_range error)
    {
        error.what();
        qDebug("string error catch");
//        exit(1);
    }

    data_file.close();

//    p_cryptor->encryptFile();
}

void ePasswordCore::writeFile()
{
    buffer.clear();
    data_file.open(QFile::WriteOnly);

    QString value;

//    p_cryptor->decryptFile();

    for(iter = elements.begin(); iter != elements.end(); ++iter)
    {
        value = iter.value();

        buffer.append(value + '\n');
    }

    data_file.write(buffer);
    data_file.close();

//    p_cryptor->encryptFile();
}

void ePasswordCore::addElement(QString name, QString password, QString note)
{
    elements.insertMulti(name, note);
    elements.insertMulti(name, password);
    elements.insertMulti(name, name);
}

void ePasswordCore::removeElement(QString name)
{
    iter = elements.find(name);

    elements.erase(iter++);
    elements.erase(iter++);
    elements.erase(iter++);
}

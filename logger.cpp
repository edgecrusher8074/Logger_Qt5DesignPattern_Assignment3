#include "logger.h"

#include <QFile>
#include <QTextStream>
#include <QDateTime>

#include <QDebug>

#include <iostream>

Logger::Logger(const QString &fileName, QObject *parent)
    : QObject(parent)
    , m_fileName(fileName)
{
}

Logger::~Logger() = default;

bool Logger::add(const QString& message) const
{
    if(m_fileName.isEmpty())
    {
        qInfo() << "Filename is empty!";
        return false;
    }

    QFile file(m_fileName);
    if(!file.open(QFile::WriteOnly | QFile::Append))
    {
        qInfo() << "Unable to open: " << m_fileName;
        return false;
    }

    if(message.isEmpty())
    {
        qInfo() << "Can not write emtpy string to file!";
        return false;
    }

    QTextStream output(&file);
    output << getTimeStamp() << ": '" << message << "'\n";
    file.close();
    return true;
}

QString Logger::getTimeStamp() const
{
    auto current = QDateTime::currentDateTime();
    return current.toString(QString("yyyy-MM-dd HH:mm:ss.zzz"));
}

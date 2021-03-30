#include <QCoreApplication>
#include <QDebug>
#include <QTextStream>

/**
 * @brief Assignment 3 for Qt5 Design Patterns Tutorial on Udemy.
 * @details This project is based on the previous assignment.
 * @todo Make a class or method as secure as possible, without
 * making it to complex or not-understandable.
 * @author edgecrusher8074
 */
#include "logger.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QTextStream stream(stdin);
    QString line;

    Logger fileLogger("stdin.log");

    int errCount = 0;

    while (stream.readLineInto(&line))
    {
        if(!fileLogger.add(line))
            errCount++;
    }

    qInfo() << "Done; counted " << errCount << "problems.";
    return a.exec();
}

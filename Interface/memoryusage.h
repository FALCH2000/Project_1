#ifndef MEMORYUSAGE_H
#define MEMORYUSAGE_H

#include <QObject>


class MemoryUsage: public QObject
{
    Q_OBJECT

public:
    MemoryUsage();

    int parseLine(char* line);

    QString getValue();


signals:
    void valueChanged(QString result);
};

#endif // MEMORYUSAGE_H

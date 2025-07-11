#ifndef DATA_CONTROLLER_H
#define DATA_CONTROLLER_H

#include <QObject>

class DataController : public QObject
{
public:
    explicit DataController(QObject* parent = nullptr);

    void setFile(QString pathToFile);

private:
    QString m_path;
};

#endif // DATA_CONTROLLER_H

#include "data_controller.h"

DataController::DataController(QObject* parent)
    : QObject(parent)
{}

void DataController::setFile(QString pathToFile)
{
    m_path = pathToFile;
}

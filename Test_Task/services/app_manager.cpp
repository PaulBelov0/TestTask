#include "app_manager.h"

AppManager::AppManager(QObject* parent)
    : QObject(parent)
{}

void AppManager::setFile(QString pathToFile)
{
    m_path = pathToFile;
}

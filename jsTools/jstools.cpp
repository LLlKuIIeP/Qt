#include "jstools.hpp"

JSTools::JSTools(QWidget *parent): QObject(parent)
{
}

void JSTools::print(const QString &str)
{
    qDebug() << str;
}

void JSTools::alert(const QString strMessage)
{
    QMessageBox::information(nullptr, "", strMessage);
}

void JSTools::quitApplication()
{
    qApp->quit();
}

QStringList JSTools::dirEntryList(const QString strDir, const QString strExt)
{
    QDir dir(strDir);
    return  dir.entryList(strExt.split(" "), QDir::Files);
}



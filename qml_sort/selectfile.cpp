#include <qdebug.h>

#include "selectfile.h"


SelectFile::SelectFile(QObject *parent) :
    QObject(parent) {

}

const QString SelectFile::GetInputFileName() const {
    return m_input_file;
}

const QString SelectFile::GetOutputFileName() const {
    return m_save_file;
}

void SelectFile::slot_select_file(QString f) {
    m_input_file = f.replace(QString("/"), QString("\\")) ;
    qDebug() << "SelectFile :" + m_input_file;
    emit signsl_selected_file(this);
}

void SelectFile::slot_save_file(QString s) {
    m_save_file = m_input_file.left(m_input_file.lastIndexOf('\\') + 1) + s + ".txt";
    //qDebug() << "Save File :" + m_save_file;
    emit signsl_save_file();
}


#ifndef SELECTFILE_H
#define SELECTFILE_H

#include <iostream>

#include <QObject>
#include <qdebug.h>

class SelectFile : public QObject
{
    Q_OBJECT
public:
    explicit SelectFile(QObject *parent = nullptr);

    const QString GetInputFileName() const;
    const QString GetOutputFileName() const;

signals:
    void signsl_selected_file(SelectFile*);
    void signsl_save_file();

public slots:
    void slot_select_file(QString f);
    void slot_save_file(QString s);

private:
    QString m_input_file;
    QString m_save_file;
};



#endif // SELECTFILE_H

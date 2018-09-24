#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>

#include "selectfile.h"
#include "parallel_sort.h"
int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;

    QObject *item = engine.rootObjects()[0];

    SelectFile *file = new SelectFile(item);
    ParallelSort *par_sort = new ParallelSort(item);
    //QQmlContext *context = new QQmlContext(engine.rootContext());
    //context->setContextProperty("parallelSort", par_sort);
    engine.rootContext()->setContextProperty("parallelSort", par_sort); // сигналы из С++ в QML

    QObject::connect(item, SIGNAL(qml_select_file(QString)), file, SLOT(slot_select_file(QString)));
    QObject::connect(file, SIGNAL(signsl_selected_file(SelectFile*)), par_sort, SLOT(slot_init_file(SelectFile*)));
    QObject::connect(file, SIGNAL(signsl_save_file()), par_sort, SLOT(slot_save_file()));
    QObject::connect(item, SIGNAL(qml_run()), par_sort, SLOT(slot_run()));
    QObject::connect(item, SIGNAL(qml_pause()), par_sort, SLOT(slot_pause()));
    QObject::connect(item, SIGNAL(qml_resume()), par_sort, SLOT(slot_resume()));
    QObject::connect(item, SIGNAL(qml_stop()), par_sort, SLOT(slot_stop()));
    QObject::connect(item, SIGNAL(qml_save(QString)), file, SLOT(slot_save_file(QString)));

    return app.exec();
}

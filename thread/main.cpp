//Листинг 38.1
#include <QtWidgets>
#include "myworker.hpp"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    QLCDNumber lcd;
    QThread thread;                                                                     //объект управляющий потоком
    MyWorker worker;                                                                    //объект, который будет выполнятся в потоке

    QObject::connect(&worker, SIGNAL(valueChanged(int)), &lcd, SLOT(display(int)));     //отправка сигнала из потока worker в дисплей

    lcd.setSegmentStyle(QLCDNumber::Filled);
    lcd.display(10);
    lcd.resize(220, 90);
    lcd.show();

    worker.moveToThread(&thread);           //передает объект в поток, потому что thread только управляет потоками, но не создает их

    QObject::connect(&thread, SIGNAL(started()), &worker, SLOT(slotDoWork()));

    QObject::connect(&worker, SIGNAL(finished()), &app, SLOT(quit()));

    thread.start();

    int nResult = app.exec();

    thread.quit();  //поток не завершится, пока работает цикл
    thread.wait();  //ждем завершения цикла, и завершения потока соответственно

    return nResult;
}

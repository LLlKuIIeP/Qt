//Листинг 26.10
#include <QtWidgets>
#include <QDebug>
int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    QWidget wgt;

    QPushButton *pcmdA = new QPushButton("Button 1");
    QPushButton *pcmdB = new QPushButton("Button 2");
    QPushButton *pcmdC = new QPushButton("Button 3");

    QVBoxLayout *pvbxLayout = new QVBoxLayout;
    pvbxLayout->addWidget(pcmdA);
    pvbxLayout->addWidget(pcmdB);
    pvbxLayout->addWidget(pcmdC);
    wgt.setLayout(pvbxLayout);


    QFile file(":/qss/simple.qss");
    file.open(QFile::ReadOnly);
    if(file.isOpen()) {
        qDebug() << "File Is Open";
    }
    else {
        qDebug() << "File Is Not Open";
    }
    QString strCSS = QLatin1String(file.readAll());

    qApp->setStyleSheet(strCSS);
    wgt.show();

    return app.exec();
}

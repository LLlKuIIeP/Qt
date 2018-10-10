//Листинг 10.5
#include <QtWidgets>
#include "syntaxhighligher.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    QTextEdit txt;

    QFont fnt("Lucida Console", 9, QFont::Normal);
    txt.document()->setDefaultFont(fnt);
    new SyntaxHighligher(txt.document());   //объект txt позаботится об уничтожении SyntaxHighligher при своем разрушении

    QPalette pal = txt.palette();
    pal.setColor(QPalette::Base, Qt::darkBlue);
    pal.setColor(QPalette::Text, Qt::yellow);
    txt.setPalette(pal);

    txt.resize(640, 480);
    txt.show();

    QFile file(":/syntaxhighligher.cpp");
    file.open(QFile::ReadOnly);
    txt.setPlainText(QLatin1String(file.readAll()));

    return app.exec();
}

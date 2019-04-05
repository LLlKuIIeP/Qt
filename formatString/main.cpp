#include <iostream>
#include <sstream>
#include <QtCore>


QString toString(QString str)
{
    return str;
}

QString toString(bool b)
{
    std::stringstream ss;
    ss << std::boolalpha << b;

    std::string str;
    ss >> str;

    return QString(str.c_str());
}

template<class T>
QString toString(T arg)
{
    std::stringstream ss;
    ss << arg;

    std::string str;
    ss >> str;

    return QString(str.c_str());
}

template<class... Args>
QString formatString(QString format, Args... args)
{
    QString str[] = { toString(args)... };

    for(auto &elem: str) {
        format = format.arg(elem);
    }

    return format;
}


int main(int argc, char *argv[])
{
    Q_UNUSED(argc)
    Q_UNUSED(argv)


    qDebug() << formatString("sdfsdf %1", "www");
    return 0;
}

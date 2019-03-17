#pragma once

#include <QObject>


class SomeClass
{
public:
    SomeClass();
    SomeClass(const SomeClass&) = default;
    ~SomeClass() = default;

    friend QDataStream& operator<<(QDataStream &ostream, const SomeClass &some);
    friend QDataStream& operator>>(QDataStream &istream, const SomeClass &some);
};
Q_DECLARE_METATYPE(SomeClass)

QDataStream& operator<<(QDataStream &ostream, const SomeClass &some);
QDataStream& operator>>(QDataStream &istream, const SomeClass &some);

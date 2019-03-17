#include "someclass.h"


SomeClass::SomeClass()
{
}

QDataStream& operator<<(QDataStream &ostream, const SomeClass &some)
{
    Q_UNUSED(some);

    return ostream;
}

QDataStream& operator>>(QDataStream &istream, const SomeClass &some)
{
    Q_UNUSED(some);

    return istream;
}

#include "namevalidator.h"

NameValidator::NameValidator(QObject *parent) : QValidator(parent) {
}

QValidator::State NameValidator::validate(QString &str, int &pos) const {
    QRegExp rxp = QRegExp("[0-9]");
    if (str.contains(rxp)) {
        return Invalid;
    }
    return Acceptable;
}


#pragma once

#include <QtWidgets>
#include <QValidator>

class NameValidator : public QValidator {
    Q_OBJECT
public:
    NameValidator(QObject *parent = 0);

    virtual State validate(QString &, int&) const;
};

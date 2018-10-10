#pragma once

//#include <QWidget>
#include <QSyntaxHighlighter>

class QTextDocument;

class SyntaxHighligher : public QSyntaxHighlighter
{
    Q_OBJECT

public:
    SyntaxHighligher(QTextDocument *parent = nullptr);

protected:
    enum { NormalState = -1,    //нормальное состояние, когда используется расцветка
           InsideCStyleComment, //текущая позиция находится внутри строки, тогда подцветка Qt::cyan
           InsideCString        //когда позиция находится в комментарии /*...*/, тогда Qt::darkGray
          };
    virtual void highlightBlock(const QString&);
    QString getKeyword(int, const QString&) const;    //находит ключевые слова С++ и Qt

private:
    QStringList m_lstKeywords;
};

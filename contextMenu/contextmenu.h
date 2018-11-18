#pragma once

#include <QtWidgets>

class ContextMenu: public QTextEdit {
    Q_OBJECT

public:
    ContextMenu(QWidget *parent = nullptr);

public slots:
    void slotActivated(QAction *);

protected:
    void contextMenuEvent(QContextMenuEvent *) override;

private:
    QMenu *m_pmnu;
};

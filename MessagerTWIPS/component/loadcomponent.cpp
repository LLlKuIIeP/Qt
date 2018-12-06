#include <QQmlContext>
#include <QDebug>

#include "connector/connector.hpp"
#include "loadcomponent.hpp"

LoadComponent::LoadComponent(QQmlApplicationEngine *engine, QObject *parent) : QObject(parent), m_pobject(nullptr), m_pengine(engine)
{
    m_pengine->load(QUrl(QStringLiteral("qrc:/main.qml")));
    if (m_pengine->rootObjects().isEmpty()) {
        qWarning() << "LoadComponent::LoadComponent: Error load";
        //return -1;
    }

    m_pobject = m_pengine->rootObjects()[0];
    connect(m_pobject, SIGNAL(qml_signal_next_page(QString)), this, SLOT(slotLoadPage(QString)));
}

void LoadComponent::slotLoadPage(QString page_name)
{
    disconnect(m_pobject, SIGNAL(qml_signal_next_page(QString)), this, SLOT(slotLoadPage(QString)));
    m_pengine->load(QUrl(QStringLiteral("qrc:/") + page_name));

    m_pengine->rootContext()->setContextProperty("rootResponse", Connector::Instance().getResponse());

    m_pobject = m_pengine->rootObjects().last();

    connect(m_pobject, SIGNAL(qml_signal_next_page(QString)), this, SLOT(slotLoadPage(QString)));
}

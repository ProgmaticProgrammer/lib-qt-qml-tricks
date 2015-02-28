
#include <QGuiApplication>
#include <QQuickView>
#include <QQmlContext>
#include <QQmlEngine>
#include <QUrl>
#include <qqml.h>

#include <QQmlSvgIconHelper>

int main (int argc, char * argv []) {
    QGuiApplication app (argc, argv);

    QQmlSvgIconHelper::setBasePath ("://");
    qmlRegisterType<QQmlSvgIconHelper> ("QtQmlTricks", 1, 0, "SvgIconHelper");

    QQuickView view;
    view.engine ()->addImportPath (QML_TRICK_IMPORT);
    view.setResizeMode (QQuickView::SizeRootObjectToView);
    view.setSource (QUrl ("qrc:/ui.qml"));
    view.show ();

    return app.exec ();
}


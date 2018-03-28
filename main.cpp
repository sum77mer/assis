#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QtQml/QQmlApplicationEngine>
#include <QApplication>
//*************************
#include <QDir>
#include <QGuiApplication>
#include <QQmlEngine>
#include <QQmlFileSelector>
#include <QQmlContext>
#include <QQuickView> //Not using QQmlApplicationEngine because many examples don't have a Window{}
//***************************
#include "backend.h"
//**********************
#include "cpuid.h"
#include "BIOS.h"
int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    //QGuiApplication app(argc, argv);
    QApplication app(argc,argv);

    Info_out CPUID_info;
    CPUID_Data Save_CPU_Data;
    CPUID_info.excute_CPUID();
    Save_CPU_Data = CPUID_info.RES_DATA;

    BIOS bios_info;
    bios_info.excute();
    BIOS_Data Save_BIOS_Data = bios_info.Return_BIOS_info();
//******************************************************************************
    qmlRegisterType<Back_End>("io.qt.examples.backend", 1, 0, "BackEnd");
    //qmlRegisterType<MyMenu>("io.qt.mymenu",1,0,"MyMenu");
    //qmlRegisterType<Info_out>("io.qt.examples.backend", 1, 0, "Info_out");
//********************************************************************************
    //QQmlApplicationEngine engine;
    //engine.load(QUrl(QLatin1String("qrc:/qml/main.qml")));
    //engine.setResizeMode(QQuickView::SizeRootObjectToView);
    //if (engine.rootObjects().isEmpty())
    //    return -1;
    QQuickView view;
    if (qgetenv("QT_QUICK_CORE_PROFILE").toInt()) {
        QSurfaceFormat f = view.format();
        f.setProfile(QSurfaceFormat::CoreProfile);
        f.setVersion(4, 4);
        view.setFormat(f);
    }
    view.connect(view.engine(), &QQmlEngine::quit, &app, &QCoreApplication::quit);
    new QQmlFileSelector(view.engine(), &view);
    view.setSource(QUrl("qrc:/qml/main.qml"));
    if (view.status() == QQuickView::Error)
        return -1;
    view.setResizeMode(QQuickView::SizeRootObjectToView);
    view.setFlags(Qt::Window|Qt::FramelessWindowHint);
    view.setColor(QColor(Qt::transparent));
    view.rootContext()->setContextProperty("window",&view);
    if (QGuiApplication::platformName() == QLatin1String("qnx") ||
          QGuiApplication::platformName() == QLatin1String("eglfs")) {
        view.showFullScreen();
    } else {
        view.show();
    }
    return app.exec();
}

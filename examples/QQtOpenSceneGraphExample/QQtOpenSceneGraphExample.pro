#-------------------------------------------------
#
# Project created by QtCreator 2018-05-29T18:07:40
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = QQtOpenSceneGraphExample
TEMPLATE = app

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
        mainwindow.cpp

HEADERS += \
        mainwindow.h

FORMS += \
        mainwindow.ui

include (../../multi-link/add_base_manager.pri)
include (../../app-lib/add_library_OpenSceneGraph.pri)

system(touch mainwindow.cpp)
add_version(1,0,0,0)
add_deploy()
add_dependent_library_QQt()
mingw{
    #Qt is static, but osg is dynamic
    #add_defines(OSG_LIBRARY_STATIC)
    add_defines(__MINGW32__)
}
add_dependent_library_OpenSceneGraph()
add_deploy_config($${PWD}/AppRoot)
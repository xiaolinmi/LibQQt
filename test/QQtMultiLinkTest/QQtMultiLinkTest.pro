#-------------------------------------------------
#
# Project created by QtCreator 2018-05-20T13:55:04
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = QQtMultiLinkTest
TEMPLATE = app

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

system(touch main.cpp)
include (../../multi-link/add_base_manager.pri)

#链接QQt
add_library(QQt)
#包含QQt的头文件
add_qqt_header()

#app从build到deploy
add_deploy()
#libQQt从sdk到build和deploy
add_deploy_library(QQt)

message($$QMAKE_POST_LINK)
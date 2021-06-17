QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11
CONFIG += sdk_no_version_check

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    ../cryptoclass/cryptoclass.cpp \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    ../cryptoclass/cryptoclass.h \
    mainwindow.h

FORMS += \
    mainwindow.ui

TRANSLATIONS += \
    512hash-gui_en_GB.ts

INCLUDEPATH += \
    ../cryptoclass/

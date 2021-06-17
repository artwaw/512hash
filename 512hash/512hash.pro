QT -= gui

CONFIG += c++11 console
CONFIG -= app_bundle
CONFIG += sdk_no_version_check

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        ../cryptoclass/cryptoclass.cpp \
        main.cpp

TRANSLATIONS += \
    512hash_en_GB.ts

HEADERS += \
    ../cryptoclass/cryptoclass.h

INCLUDEPATH += \
    ../cryptoclass/

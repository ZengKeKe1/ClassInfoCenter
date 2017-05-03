#-------------------------------------------------
#
# Project created by QtCreator 2017-04-28T21:33:43
#
#-------------------------------------------------

QT       += core gui \
            sql
QT       += network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = InfoCenter
TEMPLATE = app


SOURCES += main.cpp\
    login.cpp \
    dialog.cpp \
    globle.cpp \
    fanyi.cpp \
    gpa.cpp


HEADERS  += \
    login.h \
    dialog.h \
    globle.h \
    translate.h \
    gpa.h

FORMS    += \
    login.ui \
    dialog.ui \
    fanyi.ui \
    gpa.ui


DISTFILES += \
    ../../../../../home/zengke/图片/2017-04-28 21-52-33屏幕截图.png

RESOURCES += \
    photos.qrc
CONFIG   += c++11

#-------------------------------------------------
#
# Project created by QtCreator 2018-11-14T13:36:31
#
#-------------------------------------------------

QT       += core gui

TRANSLATIONS = Translate_EN.ts\
                Translate_CN.ts\
                Translate_DE.ts

OTHER_FILES += ico.rc
RC_FILE += ico.rc

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = RA3_Cheat
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += main.cpp\
        ra3window.cpp

HEADERS  += ra3window.h

FORMS    += ra3window.ui

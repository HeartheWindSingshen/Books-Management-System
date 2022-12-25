#-------------------------------------------------
#
# Project created by QtCreator 2021-12-11T10:31:38
#
#-------------------------------------------------

QT       += core gui
QT        +=sql
CONFIG += resources_big
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = BooksManagement
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

CONFIG += c++11

SOURCES += \
        main.cpp \
        mainwindow.cpp \
    adlogin.cpp \
    relogin.cpp \
    reregister.cpp \
    radio1.cpp \
    radio2.cpp \
    adregister.cpp \
    reinformation.cpp \
    itemform.cpp \
    updatereinformation.cpp \
    itemform2.cpp \
    adreaderinformation.cpp \
    itemform3.cpp \
    adupdatereinformation.cpp \
    adreaderinformationdelete.cpp \
    bookinformation.cpp \
    adbook.cpp \
    itemform4.cpp \
    itemform5.cpp \
    adborrow.cpp \
    itemform6.cpp \
    adreturn.cpp \
    itemform7.cpp

HEADERS += \
        mainwindow.h \
    adlogin.h \
    relogin.h \
    reregister.h \
    radio1.h \
    radio2.h \
    adregister.h \
    reinformation.h \
    itemform.h \
    updatereinformation.h \
    itemform2.h \
    adreaderinformation.h \
    itemform3.h \
    adupdatereinformation.h \
    adreaderinformationdelete.h \
    bookinformation.h \
    adbook.h \
    itemform4.h \
    itemform5.h \
    adborrow.h \
    itemform6.h \
    adreturn.h \
    itemform7.h

FORMS += \
        mainwindow.ui \
    adlogin.ui \
    adregister.ui \
    relogin.ui \
    reregister.ui \
    adregister.ui \
    reinformation.ui \
    itemform.ui \
    updatereinformation.ui \
    itemform2.ui \
    adreaderinformation.ui \
    itemform3.ui \
    adupdatereinformation.ui \
    adreaderinformationdelete.ui \
    bookinformation.ui \
    adbook.ui \
    itemform4.ui \
    itemform5.ui \
    adborrow.ui \
    itemform6.ui \
    adreturn.ui \
    itemform7.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    res.qrc

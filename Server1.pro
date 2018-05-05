QT -= gui
QT +=xml
QT +=network

CONFIG += c++11 console
CONFIG -= app_bundle

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        main.cpp \
    cthread.cpp \
    cserver.cpp \
    cdatabase.cpp \
    croomlist.cpp \
    croom.cpp \
    cclienthandler.cpp

HEADERS += \
    cthread.h \
    cserver.h \
    cdatabase.h \
    croomlist.h \
    croom.h \
    cclienthandler.h

DISTFILES += \
    room1.txt \
    unregisteredaccounts.txt \
    ../build-Server1-Desktop_Qt_5_10_1_MSVC2017_64bit-Debug/users.xml

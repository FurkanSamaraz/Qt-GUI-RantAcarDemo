QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    arackayit.cpp \
    giriss.cpp \
    main.cpp \
    mainwindow.cpp \
    musterikayit.cpp \
    raporlar.cpp \
    sil.cpp \
    sozlesme.cpp

HEADERS += \
    arackayit.h \
    giriss.h \
    mainwindow.h \
    musterikayit.h \
    raporlar.h \
    sil.h \
    sozlesme.h

FORMS += \
    arackayit.ui \
    giriss.ui \
    mainwindow.ui \
    musterikayit.ui \
    raporlar.ui \
    sil.ui \
    sozlesme.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    image.qrc

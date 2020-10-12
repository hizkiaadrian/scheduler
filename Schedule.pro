QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets sql

CONFIG += c++11

SOURCES += \
    categoriessettings.cpp \
    eventcategory.cpp \
    main.cpp \
    mainwindow.cpp \
    newcategorydialog.cpp \
    neweventdialog.cpp \
    settingsdialog.cpp \
    utils.cpp

HEADERS += \
    categoriessettings.h \
    eventcategory.h \
    mainwindow.h \
    messagetype.h \
    newcategorydialog.h \
    neweventdialog.h \
    settingsdialog.h \
    utils.h

FORMS += \
    categoriessettings.ui \
    mainwindow.ui \
    newcategorydialog.ui \
    neweventdialog.ui \
    settingsdialog.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

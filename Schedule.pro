QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets sql

CONFIG += c++11

INCLUDEPATH += include/

SOURCES += \
    main.cpp \
    src/eventcategory.cpp \
    src/utils.cpp \
    src/widgets/categoriessettings.cpp \
    src/widgets/editcategorydialog.cpp \
    src/widgets/mainwindow.cpp \
    src/widgets/newcategorydialog.cpp \
    src/widgets/neweventdialog.cpp \
    src/widgets/settingsdialog.cpp


HEADERS += \
    include/eventcategory.h \
    include/messagetype.h \
    include/utils.h \
    include/widgets/categoriessettings.h \
    include/widgets/editcategorydialog.h \
    include/widgets/mainwindow.h \
    include/widgets/newcategorydialog.h \
    include/widgets/neweventdialog.h \
    include/widgets/settingsdialog.h


FORMS += \
    forms/categoriessettings.ui \
    forms/editcategorydialog.ui \
    forms/mainwindow.ui \
    forms/newcategorydialog.ui \
    forms/neweventdialog.ui \
    forms/settingsdialog.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

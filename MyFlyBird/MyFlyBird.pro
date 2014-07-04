QT += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = MyFlappyBird
TEMPLATE = app
RESOURCES += \
    MyResource.qrc

RC_ICONS = bird.ico
HEADERS += \
    flybird.h \
    mainwindow.h \
    blockpipe.h \
    moveground.h \
    scoring.h

SOURCES += \
    flybird.cpp \
    main.cpp \
    mainwindow.cpp \
    blockpipe.cpp \
    moveground.cpp \
    scoring.cpp

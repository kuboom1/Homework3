TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        component.cpp \
        main.cpp \
        menu.cpp \
        rwFunc.cpp

HEADERS += \
    component.h \
    menu.h \
    rwFunc.h

DISTFILES += \
    data.db

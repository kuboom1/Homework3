TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        component.cpp \
        main.cpp \
        rwFunc.cpp

HEADERS += \
    component.h \
    rwFunc.h

DISTFILES += \
    data.db

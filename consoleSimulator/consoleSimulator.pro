TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        main.cpp \
        simulator.cpp \
        simulatorinterface.cpp

HEADERS += \
    cell.h \
    simulator.h \
    simulatorinterface.h

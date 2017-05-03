#TEMPLATE = lib
TEMPLATE = app
CONFIG += console
CONFIG -= qt

SOURCES += lab3.cpp \
    main.cpp

HEADERS += \
    lab3.h

TARGET = ordered_table
DESTDIR = lib

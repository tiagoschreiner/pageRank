TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.c \
    pageRank.cpp

include(deployment.pri)
qtcAddDeployment()

HEADERS += \
    pageRank.h


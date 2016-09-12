QT += core
QT -= gui

CONFIG += c++11

TARGET = PokerBot
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    Game.cpp

include(PlayerMath/PlayerMath.pri)
include(Entities/Entities.pri)
include(Tools/Tools.pri)

HEADERS += \
    Game.h

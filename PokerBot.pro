QT += core widgets

CONFIG += c++11

TARGET = PokerBot
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    Game.cpp

HEADERS += \
    Game.h

include(PlayerMath/PlayerMath.pri)
include(Entities/Entities.pri)
include(Tools/Tools.pri)
include(Widgets/Widgets.pri)

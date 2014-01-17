APP_NAME = VservBB10SampleApp

CONFIG += qt warn_on cascades10
INCLUDEPATH += BlackberryCascadeLib.hpp
LIBS += -LD:/Blackberry_10/VservBB10SampleApp/lib -lBlackberryCascadeLib
LIBS += -lbbdata
LIBS += -lbbdevice
LIBS += -lbbpim
LIBS += -lbb
QT += network
include(config.pri)

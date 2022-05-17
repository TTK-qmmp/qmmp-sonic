include($$PWD/../../plugins.pri)

TARGET = $$PLUGINS_PREFIX/Effect/sonic

HEADERS += sonicplugin.h \
           effectsonicfactory.h \
           settingsdialog.h

SOURCES += sonicplugin.cpp \
           effectsonicfactory.cpp \
           settingsdialog.cpp \
           libsonic/sonic.c

FORMS += settingsdialog.ui

INCLUDEPATH += $$PWD/libsonic

unix{
    target.path = $$PLUGIN_DIR/Effect
    INSTALLS += target
}

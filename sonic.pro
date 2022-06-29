HEADERS += sonicplugin.h \
           effectsonicfactory.h \
           settingsdialog.h

SOURCES += sonicplugin.cpp \
           effectsonicfactory.cpp \
           settingsdialog.cpp \
           libsonic/sonic.c

FORMS += settingsdialog.ui

INCLUDEPATH += $$PWD/libsonic

#CONFIG += BUILD_PLUGIN_INSIDE
contains(CONFIG, BUILD_PLUGIN_INSIDE){
    include($$PWD/../../plugins.pri)
    TARGET = $$PLUGINS_PREFIX/Effect/sonic

    unix{
        target.path = $$PLUGIN_DIR/Effect
        INSTALLS += target
    }
}else{
    QT += widgets
    CONFIG += warn_off plugin lib thread link_pkgconfig c++11
    TEMPLATE = lib

    unix{
        PKGCONFIG += qmmp-1

        PLUGIN_DIR = $$system(pkg-config qmmp-1 --variable=plugindir)/Effect
        INCLUDEPATH += $$system(pkg-config qmmp-1 --variable=prefix)/include

        plugin.path = $${PLUGIN_DIR}
        plugin.files = lib$${TARGET}.so
        INSTALLS += plugin
    }
}

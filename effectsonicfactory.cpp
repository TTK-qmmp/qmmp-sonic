#include "effectsonicfactory.h"
#include "sonicplugin.h"
#include "settingsdialog.h"

#include <QMessageBox>

#if (QMMP_VERSION_INT < 0x10700) || (0x20000 <= QMMP_VERSION_INT && QMMP_VERSION_INT < 0x20200)
const EffectProperties EffectSonicFactory::properties() const
#else
EffectProperties EffectSonicFactory::properties() const
#endif
{
    EffectProperties properties;
    properties.name = tr("Speed Pitch Plugin");
    properties.shortName = "sonic";
    properties.hasSettings = true;
    properties.hasAbout = true;
    return properties;
}

Effect *EffectSonicFactory::create()
{
    return new SonicPlugin();
}

#if (QMMP_VERSION_INT < 0x10700) || (0x20000 <= QMMP_VERSION_INT && QMMP_VERSION_INT < 0x20200)
void EffectSonicFactory::showSettings(QWidget *parent)
{
    (new SettingsDialog(parent))->show();
}
#else
QDialog *EffectSonicFactory::createSettings(QWidget *parent)
{
    return new SettingsDialog(parent);
}
#endif

void EffectSonicFactory::showAbout(QWidget *parent)
{
     QMessageBox::about(parent, tr("About Speed Pitch Effect Plugin"),
                        tr("Qmmp Speed Pitch Effect Plugin") + "\n" +
                        tr("Written by: Greedysky <greedysky@163.com>") + "\n" +
                        tr("Based on the source code from the sonic") + "\n" +
                        tr("Written by Bill Cox (C) 2010"));
}

QString EffectSonicFactory::translation() const
{
    return QString();
}

#if QT_VERSION < QT_VERSION_CHECK(5,0,0)
#include <QtPlugin>
Q_EXPORT_PLUGIN2(sonic, EffectSonicFactory)
#endif

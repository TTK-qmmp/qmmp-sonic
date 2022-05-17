#include "effectsonicfactory.h"
#include "sonicplugin.h"
#include "settingsdialog.h"

#include <QMessageBox>

const EffectProperties EffectSonicFactory::properties() const
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

void EffectSonicFactory::showSettings(QWidget *parent)
{
    (new SettingsDialog(parent))->show();
}

void EffectSonicFactory::showAbout(QWidget *parent)
{
     QMessageBox::about(parent, tr("About Speed Pitch Effect Plugin"),
                        tr("Qmmp Speed Pitch Effect Plugin") + "\n" +
                        tr("Written by: Greedysky <greedysky@163.com>"));
}

QString EffectSonicFactory::translation() const
{
    return QString();
}

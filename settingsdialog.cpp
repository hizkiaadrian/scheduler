#include "settingsdialog.h"
#include "ui_settingsdialog.h"

SettingsDialog::SettingsDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SettingsDialog),
    windowTitle("Settings")
{
    ui->setupUi(this);

    this->setWindowTitle(windowTitle);
}

SettingsDialog::~SettingsDialog()
{
    delete ui;
}

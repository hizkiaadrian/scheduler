#include "settingsdialog.h"
#include "ui_settingsdialog.h"
#include <QVBoxLayout>

SettingsDialog::SettingsDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SettingsDialog)
{
    ui->setupUi(this);

    ui->tabWidget->addTab(new QWidget(), "Categories");

}

SettingsDialog::~SettingsDialog()
{
    delete ui;

}

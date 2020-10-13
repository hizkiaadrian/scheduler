#include <QVBoxLayout>

#include "widgets/settingsdialog.h"
#include "widgets/categoriessettings.h"
#include "ui_settingsdialog.h"

SettingsDialog::SettingsDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SettingsDialog)
{
    ui->setupUi(this);

    ui->tabWidget->addTab(new CategoriesSettings, "Categories");

}

SettingsDialog::~SettingsDialog()
{
    delete ui;

}

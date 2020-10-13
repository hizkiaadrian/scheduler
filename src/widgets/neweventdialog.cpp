#include "neweventdialog.h"
#include "./ui_neweventdialog.h"

#include "eventcategory.h"

#include <QSqlQuery>

NewEventDialog::NewEventDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::NewEventDialog)
{
    ui->setupUi(this);

    ui->comboBox->addItems(EventCategory::getAllCategories());

}

NewEventDialog::~NewEventDialog()
{
    delete ui;

}

#include "neweventdialog.h"
#include "./ui_neweventdialog.h"

#include <QSqlQuery>

NewEventDialog::NewEventDialog(QSqlDatabase dbConnection, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::NewEventDialog),
    dbConnection(dbConnection)
{
    ui->setupUi(this);

    QSqlQuery query(dbConnection);
    query.exec("SELECT name FROM categories");
    while (query.next()) {
        ui->comboBox->addItem(query.value(0).toString());
    }

}

NewEventDialog::~NewEventDialog()
{
    delete ui;
}

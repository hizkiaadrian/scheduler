#include "neweventdialog.h"
#include "./ui_neweventdialog.h"

#include <QSqlQuery>

NewEventDialog::NewEventDialog(QSqlDatabase dbConnection, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::NewEventDialog),
    windowTitle("Add a new event"),
    dbConnection(dbConnection)
{
    ui->setupUi(this);

    this->setWindowTitle(windowTitle);

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

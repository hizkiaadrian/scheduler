#include "newcategorydialog.h"
#include "ui_newcategorydialog.h"

#include <QSqlDatabase>
#include <QDebug>
NewCategoryDialog::NewCategoryDialog(QSqlDatabase dbConnection, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::NewCategoryDialog),
    dbConnection(dbConnection)
{
    ui->setupUi(this);
}

NewCategoryDialog::~NewCategoryDialog()
{
    delete ui;
}

void NewCategoryDialog::on_lineEdit_editingFinished()
{
    ui->label->setText(ui->lineEdit->text());
}

#include "newcategorydialog.h"
#include "ui_newcategorydialog.h"
#include "eventcategory.h"

#include <QSqlDatabase>
#include <QSqlQuery>
#include <QDebug>

NewCategoryDialog::NewCategoryDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::NewCategoryDialog)
{
    ui->setupUi(this);

}

NewCategoryDialog::~NewCategoryDialog()
{
    delete ui;

}

void NewCategoryDialog::on_lineEdit_editingFinished(){}

void NewCategoryDialog::on_buttonBox_accepted()
{
    if(EventCategory::addNewCategory(ui->lineEdit->text()))
        qDebug() << "Category " + ui->lineEdit->text() + " added successfully";

}

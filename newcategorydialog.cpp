#include "newcategorydialog.h"
#include "ui_newcategorydialog.h"
#include "eventcategory.h"

#include <QSqlDatabase>
#include <QSqlQuery>
#include <QDebug>
#include <QPushButton>

NewCategoryDialog::NewCategoryDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::NewCategoryDialog)
{
    ui->setupUi(this);

    ui->lineEdit->setPlaceholderText("Type a category name...");
    ui->buttonBox->button(QDialogButtonBox::Ok)->setEnabled(false);
}

NewCategoryDialog::~NewCategoryDialog()
{
    delete ui;

}


void NewCategoryDialog::on_lineEdit_textEdited(const QString &value)
{
    if(value.isEmpty())
        ui->buttonBox->button(QDialogButtonBox::Ok)->setEnabled(false);
    else if (EventCategory::getAllCategories().contains(value)){
        ui->buttonBox->button(QDialogButtonBox::Ok)->setEnabled(false);
        qDebug() << "Category exists";
    }
    else
        ui->buttonBox->button(QDialogButtonBox::Ok)->setEnabled(true);
}


void NewCategoryDialog::on_buttonBox_accepted()
{
    if(EventCategory::addNewCategory(ui->lineEdit->text()))
        qDebug() << "Category " + ui->lineEdit->text() + " added successfully";

}

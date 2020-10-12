#include "editcategorydialog.h"
#include "ui_editcategorydialog.h"
#include "eventcategory.h"

EditCategoryDialog::EditCategoryDialog(QString category, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EditCategoryDialog),
    existingCategories(EventCategory::getAllCategories()),
    category(category)
{
    ui->setupUi(this);

    this->setWindowTitle("Edit Category: " + category);
    ui->lineEdit->setText(category);
}


EditCategoryDialog::~EditCategoryDialog()
{
    delete ui;
}


void EditCategoryDialog::on_deleteButton_clicked()
{
    bool deleteSuccess = EventCategory::deleteCategory(category);

    if(deleteSuccess)
    {
        emit deleteSuccessful();
        this->close();
    }
}

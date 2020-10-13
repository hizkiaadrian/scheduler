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
    ui->saveChangesButton->setEnabled(false);
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
        emit categoriesModified("Category " + category + " deleted succesfully");
    } else {
        emit categoriesModified("Failed to delete category " + category);
    }

    this->close();

}

void EditCategoryDialog::on_cancelButton_clicked()
{
    this->close();
}

void EditCategoryDialog::on_lineEdit_textEdited(const QString &value)
{
    if (value.isEmpty() || value == category) {
        ui->saveChangesButton->setEnabled(false);
    } else {
        ui->saveChangesButton->setEnabled(true);
    }

}

void EditCategoryDialog::on_saveChangesButton_clicked()
{
    bool updateSuccess = EventCategory::updateCategoryName(category, ui->lineEdit->text());

    if (updateSuccess)
    {
        emit categoriesModified("Category " + category + " updated successfully to " + ui->lineEdit->text());
    } else {
        emit categoriesModified("Failed to update category name");
    }

    this->close();
}

#include "editcategorydialog.h"
#include "ui_editcategorydialog.h"

EditCategoryDialog::EditCategoryDialog(QString category, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EditCategoryDialog),
    category(category)
{
    ui->setupUi(this);

    this->setWindowTitle("Edit Category: " + category);
    ui->label->setText(category);
}

EditCategoryDialog::~EditCategoryDialog()
{
    delete ui;
}

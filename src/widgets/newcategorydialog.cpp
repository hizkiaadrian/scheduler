#include <QSqlDatabase>
#include <QSqlQuery>
#include <QDebug>
#include <QPushButton>
#include <QStyle>

#include "eventcategory.h"
#include "messagetype.h"
#include "utils.h"
#include "widgets/newcategorydialog.h"
#include "ui_newcategorydialog.h"


NewCategoryDialog::NewCategoryDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::NewCategoryDialog),
    categories(EventCategory::getAllCategories())
{
    ui->setupUi(this);

    for (QString& category: categories) {
        category = category.toLower();
    }

    ui->lineEdit->setPlaceholderText("Type a category name...");
    ui->buttonBox->button(QDialogButtonBox::Ok)->setEnabled(false);
}

NewCategoryDialog::~NewCategoryDialog()
{
    delete ui;

}

void NewCategoryDialog::on_lineEdit_textEdited(const QString &value)
{
    if(value.isEmpty()){
        showMessage(ui->label, "\u2717 Cannot be empty", MessageError);
        ui->buttonBox->button(QDialogButtonBox::Ok)->setEnabled(false);
    }
    else if (categories.contains(value.toLower())){
        showMessage(ui->label, "\u2717 Category already exists", MessageError);
        ui->buttonBox->button(QDialogButtonBox::Ok)->setEnabled(false);
    }
    else {
        showMessage(ui->label, "\u2713 OK", MessageOK);
        ui->buttonBox->button(QDialogButtonBox::Ok)->setEnabled(true);
    }

}


void NewCategoryDialog::on_buttonBox_accepted()
{
    bool addCategorySuccess = EventCategory::addNewCategory(ui->lineEdit->text());

    if(addCategorySuccess) {
        emit formSubmitted("Category " + ui->lineEdit->text() + " added successfully");
    }

}

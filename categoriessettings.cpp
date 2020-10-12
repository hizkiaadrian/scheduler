#include "categoriessettings.h"
#include "ui_categoriessettings.h"
#include "eventcategory.h"
#include "editcategorydialog.h"

CategoriesSettings::CategoriesSettings(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::categoriesSettings),
    categories(EventCategory::getAllCategories())
{
    ui->setupUi(this);

    ui->listWidget->addItems(categories);

}

CategoriesSettings::~CategoriesSettings()
{
    delete ui;

}

void CategoriesSettings::on_listWidget_itemDoubleClicked(QListWidgetItem *item)
{
    EditCategoryDialog editCategoryDialog(item->text());
    editCategoryDialog.exec();
}

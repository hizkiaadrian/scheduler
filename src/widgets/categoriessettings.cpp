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
    connect(&editCategoryDialog, SIGNAL(categoriesModified(QString)), this, SLOT(refreshCategories()));
    connect(&editCategoryDialog,
            SIGNAL(categoriesModified(QString)),
            this->parent()->parent()->parent()->parent(),
            SLOT(setStatusBarText(QString)));
    editCategoryDialog.exec();

}

void CategoriesSettings::refreshCategories() {

    categories = EventCategory::getAllCategories();

    ui->listWidget->clear();
    ui->listWidget->addItems(categories);
}

#include "categoriessettings.h"
#include "ui_categoriessettings.h"
#include "eventcategory.h"

CategoriesSettings::CategoriesSettings(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::categoriesSettings),
    categories(EventCategory::getAllCategories())
{
    ui->setupUi(this);

}

CategoriesSettings::~CategoriesSettings()
{
    delete ui;
}

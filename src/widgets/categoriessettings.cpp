#include "eventcategory.h"
#include "widgets/editcategorydialog.h"
#include "widgets/categoriessettings.h"
#include "widgets/mainwindow.h"
#include "ui_categoriessettings.h"

extern MainWindow* mainWindowPtr;

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
            mainWindowPtr,
            SLOT(setStatusBarText(QString)));
    editCategoryDialog.exec();

}

void CategoriesSettings::refreshCategories() {

    categories = EventCategory::getAllCategories();

    ui->listWidget->clear();
    ui->listWidget->addItems(categories);
}

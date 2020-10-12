#include "eventcategory.h"

#include <QSqlQuery>
#include <QVariant>

extern QSqlDatabase* dbConnectionPtr;

EventCategory::EventCategory(){}

bool EventCategory::createCategoryTable() {
    QSqlQuery sqlQuery(*dbConnectionPtr);

    return sqlQuery.exec("CREATE TABLE IF NOT EXISTS categories("
                         "category_id INTEGER PRIMARY KEY AUTOINCREMENT,"
                         "name TEXT NOT NULL UNIQUE);");
}


bool EventCategory::addNewCategory(QString newCategoryName) {
    QSqlQuery sqlQuery(*dbConnectionPtr);

    sqlQuery.prepare("INSERT INTO categories (name)"
                     "VALUES (?);");
    sqlQuery.bindValue(0, newCategoryName);

    return sqlQuery.exec();

}


QStringList EventCategory::getAllCategories() {
    QStringList categories;

    QSqlQuery sqlQuery(*dbConnectionPtr);
    sqlQuery.exec("SELECT name FROM categories");

    while (sqlQuery.next())
        categories << sqlQuery.value(0).toString();

    return categories;
}

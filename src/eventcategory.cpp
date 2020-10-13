#include <QSqlQuery>
#include <QVariant>

#include "eventcategory.h"


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


bool EventCategory::deleteCategory(QString category) {
    QSqlQuery sqlQuery(*dbConnectionPtr);

    sqlQuery.prepare("DELETE FROM categories WHERE name = :name");
    sqlQuery.bindValue(":name", category);

    return sqlQuery.exec();

}

bool EventCategory::updateCategoryName(QString prevName, QString newName)
{
    QSqlQuery sqlQuery(*dbConnectionPtr);

    sqlQuery.prepare("UPDATE categories SET name = :newName where name = :prevName");
    sqlQuery.bindValue(":prevName", prevName);
    sqlQuery.bindValue(":newName", newName);

    return sqlQuery.exec();

}

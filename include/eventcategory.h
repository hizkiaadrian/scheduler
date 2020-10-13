#pragma once

#include <QStringList>

class EventCategory
{
public:
    EventCategory();

    static bool createCategoryTable();

    static bool addNewCategory(QString category);

    static QStringList getAllCategories();

    static int getCategoryId(QString category);

    static QString getCategoryNameById(int categoryId);

    static bool deleteCategory(QString category);

    static bool updateCategoryName(QString prevName, QString newName);
};

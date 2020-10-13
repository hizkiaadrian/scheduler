#pragma once

#include <QStringList>

class EventCategory
{
public:
    EventCategory();

    static bool createCategoryTable();

    static bool addNewCategory(QString category);

    static QStringList getAllCategories();

    static int getCategoryById(QString category);

    static bool deleteCategory(QString category);

    static bool updateCategoryName(QString prevName, QString newName);
};

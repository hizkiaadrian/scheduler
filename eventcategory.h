#pragma once

#include <QStringList>

class EventCategory
{
public:
    EventCategory();

    static bool createCategoryTable();

    static bool addNewCategory(QString category);

    static QStringList getAllCategories();

    static bool deleteCategory(QString category);
};

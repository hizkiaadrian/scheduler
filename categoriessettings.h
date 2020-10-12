#ifndef CATEGORIESSETTINGS_H
#define CATEGORIESSETTINGS_H

#include <QWidget>

namespace Ui {
class categoriesSettings;
}

class CategoriesSettings : public QWidget
{
    Q_OBJECT

public:
    explicit CategoriesSettings(QWidget *parent = nullptr);
    ~CategoriesSettings();

private:
    Ui::categoriesSettings *ui;
    QStringList categories;
};

#endif // CATEGORIESSETTINGS_H

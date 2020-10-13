#ifndef CATEGORIESSETTINGS_H
#define CATEGORIESSETTINGS_H

#include <QWidget>
#include <QListWidgetItem>

namespace Ui {
class categoriesSettings;
}

class CategoriesSettings : public QWidget
{
    Q_OBJECT

public:
    explicit CategoriesSettings(QWidget *parent = nullptr);
    ~CategoriesSettings();

private slots:
    void on_listWidget_itemDoubleClicked(QListWidgetItem *item);

    void refreshCategories();

private:
    Ui::categoriesSettings *ui;
    QStringList categories;
};

#endif // CATEGORIESSETTINGS_H

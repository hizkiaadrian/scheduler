#pragma once

#include <QDialog>

namespace Ui {
class EditCategoryDialog;
}

class EditCategoryDialog : public QDialog
{
    Q_OBJECT

public:
    explicit EditCategoryDialog(QString category, QWidget *parent = nullptr);
    ~EditCategoryDialog();

private slots:
    void on_deleteButton_clicked();

signals:
    void deleteSuccessful();

private:
    Ui::EditCategoryDialog *ui;
    const QStringList existingCategories;
    const QString category;
};

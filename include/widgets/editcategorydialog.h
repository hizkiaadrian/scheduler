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

    void on_cancelButton_clicked();

    void on_lineEdit_textEdited(const QString &arg1);

    void on_saveChangesButton_clicked();

signals:
    void categoriesModified(const QString&);

private:
    Ui::EditCategoryDialog *ui;
    const QStringList existingCategories;
    const QString category;
};

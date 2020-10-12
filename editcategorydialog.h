#ifndef EDITCATEGORYDIALOG_H
#define EDITCATEGORYDIALOG_H

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

private:
    Ui::EditCategoryDialog *ui;
    const QString category;
};

#endif // EDITCATEGORYDIALOG_H

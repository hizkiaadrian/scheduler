#pragma once

#include <QDialog>
#include <QSqlDatabase>

namespace Ui {
class NewCategoryDialog;
}

class NewCategoryDialog : public QDialog
{
    Q_OBJECT

public:
    explicit NewCategoryDialog(QSqlDatabase dbConnection, QWidget *parent = nullptr);

    ~NewCategoryDialog();

private slots:

    void on_lineEdit_editingFinished();

private:
    Ui::NewCategoryDialog *ui;
    const QSqlDatabase dbConnection;
};

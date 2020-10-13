#pragma once

#include <QDialog>

namespace Ui {
class NewCategoryDialog;
}

class NewCategoryDialog : public QDialog
{
    Q_OBJECT

public:
    explicit NewCategoryDialog(QWidget *parent = nullptr);

    ~NewCategoryDialog();

private slots:

    void on_buttonBox_accepted();

    void on_lineEdit_textEdited(const QString &value);

signals:
    void formSubmitted(const QString&);

private:
    Ui::NewCategoryDialog *ui;
    QStringList categories;
};

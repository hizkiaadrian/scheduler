#pragma once

#include <QDialog>
#include <QSqlDatabase>
#include <QStringList>

QT_BEGIN_NAMESPACE
namespace Ui {
class NewEventDialog;
}
QT_END_NAMESPACE

class NewEventDialog : public QDialog
{
    Q_OBJECT

public:
    explicit NewEventDialog(QSqlDatabase dbConnection, QWidget *parent = nullptr);

    ~NewEventDialog();

private:
    Ui::NewEventDialog *ui;
    const QSqlDatabase dbConnection;
};

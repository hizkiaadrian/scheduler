#pragma once

#include <QDialog>

namespace Ui {
class NewEventDialog;
}

class NewEventDialog : public QDialog
{
    Q_OBJECT

public:
    explicit NewEventDialog(QWidget *parent = nullptr);
    ~NewEventDialog();

private:
    Ui::NewEventDialog *ui;
};

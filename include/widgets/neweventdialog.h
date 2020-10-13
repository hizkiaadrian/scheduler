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

private slots:
    void on_eventTitleLineEdit_textEdited(const QString &arg1);

    void on_categoryComboBox_currentIndexChanged(int index);

    void on_remindMeBox_currentIndexChanged(int index);

    void on_buttonBox_accepted();

private:
    Ui::NewEventDialog *ui;
};

#pragma once

#include <QDialog>
#include <QMap>

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
    void setDefaultDateTime();
    QDateTime calculateReminderTime(QDateTime startDateTime, int minutes);

private slots:
    void enableIfValid();

    void on_buttonBox_accepted();

    void on_buttonBox_rejected();

signals:
    void newEventAdded(const QString& value);

private:
    Ui::NewEventDialog *ui;
    QMap<int, QString> reminderChoices;
};

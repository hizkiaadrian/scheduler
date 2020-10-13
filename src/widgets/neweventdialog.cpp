#include <QPushButton>
#include <QSqlQuery>

#include "event.h"
#include "eventcategory.h"
#include "widgets/neweventdialog.h"
#include "ui_neweventdialog.h"


NewEventDialog::NewEventDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::NewEventDialog)
{
    ui->setupUi(this);

    ui->categoryComboBox->setPlaceholderText("--Select category--");
    ui->categoryComboBox->setCurrentIndex(-1);
    ui->categoryComboBox->addItems(EventCategory::getAllCategories());

    ui->startDateEdit->setDate(QDate::currentDate());
    ui->startTimeEdit->setTime(QTime::currentTime());
    ui->endDateEdit->setDate(QDate::currentDate());
    ui->endTimeEdit->setTime(QTime::currentTime());

    ui->remindMeBox->setPlaceholderText("--Set reminder--");
    ui->remindMeBox->setCurrentIndex(-1);
    ui->remindMeBox->addItem("Never");
    ui->remindMeBox->addItem("10 minutes before");
    ui->remindMeBox->addItem("30 minutes before");
    ui->remindMeBox->addItem("1 hour before");
    ui->remindMeBox->addItem("1 day before");

    ui->buttonBox->button(QDialogButtonBox::Ok)->setEnabled(false);

}

NewEventDialog::~NewEventDialog()
{
    delete ui;

}

void NewEventDialog::on_eventTitleLineEdit_textEdited(const QString &value)
{
    if (!value.isEmpty() && ui->remindMeBox->currentIndex() >= 0 && ui->categoryComboBox->currentIndex() >= 0)
        ui->buttonBox->button(QDialogButtonBox::Ok)->setEnabled(true);
    else
        ui->buttonBox->button(QDialogButtonBox::Ok)->setEnabled(false);

}


void NewEventDialog::on_categoryComboBox_currentIndexChanged(int index)
{
    if (index >= 0 && !ui->eventTitleLineEdit->text().isEmpty() && ui->categoryComboBox->currentIndex() >= 0)
        ui->buttonBox->button(QDialogButtonBox::Ok)->setEnabled(true);
    else
        ui->buttonBox->button(QDialogButtonBox::Ok)->setEnabled(false);
}


void NewEventDialog::on_remindMeBox_currentIndexChanged(int index)
{
    if (index >= 0 && !ui->eventTitleLineEdit->text().isEmpty() && ui->remindMeBox->currentIndex() >= 0)
        ui->buttonBox->button(QDialogButtonBox::Ok)->setEnabled(true);
    else
        ui->buttonBox->button(QDialogButtonBox::Ok)->setEnabled(false);
}


void NewEventDialog::on_buttonBox_accepted()
{
    QDateTime startDateTime(ui->startDateEdit->date(), ui->startTimeEdit->time());
    QDateTime endDateTime(ui->endDateEdit->date(), ui->endDateEdit->time());

    QDateTime reminderTime;
    switch (ui->remindMeBox->currentIndex()) {
    case 0:
        reminderTime = startDateTime;
        break;

    case 1:
        reminderTime = startDateTime.addSecs(-10 * 60);
        break;

    case 2:
        reminderTime = startDateTime.addSecs(-30 * 60);
        break;

    case 3:
        reminderTime = startDateTime.addSecs(-60 * 60);
        break;

    case 4:
        reminderTime = startDateTime.addDays(-1);
        break;

    }

    Event event(ui->eventTitleLineEdit->text(),
                ui->categoryComboBox->currentText(),
                startDateTime,
                endDateTime,
                ui->locationLineEdit->text(),
                reminderTime,
                ui->remarksTextEdit->toPlainText());

    if (event.saveToDatabase()) this->close();

}

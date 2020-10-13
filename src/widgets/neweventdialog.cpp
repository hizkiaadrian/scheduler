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

    reminderChoices[0] = "Never";
    reminderChoices[10] = "10 minutes before";
    reminderChoices[30] = "30 minutes before";
    reminderChoices[60] = "1 hour before";
    reminderChoices[24 * 60] = "1 day before";

    ui->categoryComboBox->setPlaceholderText("--Select category--");
    ui->categoryComboBox->setCurrentIndex(-1);
    ui->categoryComboBox->addItems(EventCategory::getAllCategories());

    ui->remindMeBox->setPlaceholderText("--Set reminder--");
    ui->remindMeBox->setCurrentIndex(-1);
    foreach (QString value, reminderChoices) ui->remindMeBox->addItem(value);

    setDefaultDateTime();

    ui->buttonBox->button(QDialogButtonBox::Ok)->setEnabled(false);

    connect(ui->eventTitleLineEdit, SIGNAL(textEdited(QString)), this, SLOT(enableIfValid()));
    connect(ui->remindMeBox, SIGNAL(currentIndexChanged(int)), this, SLOT(enableIfValid()));
    connect(ui->categoryComboBox, SIGNAL(currentIndexChanged(int)), this, SLOT(enableIfValid()));

}


NewEventDialog::~NewEventDialog()
{
    delete ui;

}


void NewEventDialog::setDefaultDateTime() {
    QDateTime defaultStartDateTime = QDateTime::currentDateTime();
    QDateTime defaultEndDateTime = QDateTime::currentDateTime().addSecs(60 * 60);

    ui->startDateEdit->setDate(defaultStartDateTime.date());
    ui->startTimeEdit->setTime(defaultStartDateTime.time());
    ui->endDateEdit->setDate(defaultEndDateTime.date());
    ui->endTimeEdit->setTime(defaultEndDateTime.time());
}


QDateTime NewEventDialog::calculateReminderTime(QDateTime startDateTime, int minutes) {
    return startDateTime.addSecs(- minutes * 60);

}


void NewEventDialog::on_buttonBox_accepted()
{
    QDateTime startDateTime(ui->startDateEdit->date(), ui->startTimeEdit->time());
    QDateTime endDateTime(ui->endDateEdit->date(), ui->endDateEdit->time());

    QDateTime reminderTime = calculateReminderTime(startDateTime,
                                                   reminderChoices.key(ui->remindMeBox->currentText()));

    Event event(ui->eventTitleLineEdit->text(),
                ui->categoryComboBox->currentText(),
                startDateTime,
                endDateTime,
                ui->locationLineEdit->text(),
                reminderTime,
                ui->remarksTextEdit->toPlainText());

    if (event.saveToDatabase()) {
        emit newEventAdded("Event " + ui->eventTitleLineEdit->text() + " added successfully");
        this->close();
    }

}

void NewEventDialog::on_buttonBox_rejected()
{
    this->close();

}


void NewEventDialog::enableIfValid() {
    bool isFormValid = !ui->eventTitleLineEdit->text().isEmpty()
            && ui->remindMeBox->currentIndex() >= 0
            && ui->categoryComboBox->currentIndex() >= 0;

    ui->buttonBox->button(QDialogButtonBox::Ok)->setEnabled(isFormValid);

}

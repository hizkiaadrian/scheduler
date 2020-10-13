#include "mainwindow.h"
#include "./ui_mainwindow.h"

#include "newcategorydialog.h"
#include "neweventdialog.h"
#include "settingsdialog.h"
#include "eventcategory.h"
#include "utils.h"

#include <QDir>
#include <QSqlDatabase>
#include <QStandardPaths>

extern QSqlDatabase* dbConnectionPtr;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connectToDatabase(QStandardPaths::writableLocation(QStandardPaths::AppDataLocation), dbConnection);

    dbConnectionPtr = &dbConnection;

    ui->statusbar->showMessage(dbConnection.open()
                               ? "Connected to database"
                               : "Failed to connect to database");

    if (dbConnection.open())
        EventCategory::createCategoryTable();

}


MainWindow::~MainWindow()
{
    delete ui;

}


void MainWindow::on_actionEvent_triggered()
{
    NewEventDialog newEventDialog;
    newEventDialog.exec();

}


void MainWindow::on_actionEvent_Category_triggered()
{
    NewCategoryDialog newCategoryDialog(this);

    connect(&newCategoryDialog, SIGNAL(formSubmitted(QString)), this, SLOT(setStatusBarText(QString)));

    newCategoryDialog.exec();
}


void MainWindow::on_actionSettings_triggered()
{
    SettingsDialog settingsDialog(this);
    settingsDialog.exec();

}


void MainWindow::on_actionExit_triggered()
{
    QApplication::quit();

}

void MainWindow::setStatusBarText(const QString& text)
{
    ui->statusbar->showMessage(text);
}

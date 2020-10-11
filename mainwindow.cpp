#include "mainwindow.h"
#include "./ui_mainwindow.h"

#include "newcategorydialog.h"
#include "neweventdialog.h"
#include "settingsdialog.h"
#include "eventcategory.h"

#include <QDir>
#include <QSqlDatabase>
#include <QStandardPaths>

extern QSqlDatabase* dbConnectionPtr;

void connectToDatabase(QString dbFolder, QSqlDatabase &dbConnection);

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
    NewCategoryDialog newCategoryDialog;
    newCategoryDialog.exec();

}


void MainWindow::on_actionSettings_triggered()
{
    SettingsDialog settingsDialog;
    settingsDialog.exec();

}


void MainWindow::on_actionExit_triggered()
{
    QApplication::quit();

}


void connectToDatabase(QString dbFolder, QSqlDatabase &dbConnection)
{
    dbConnection = QSqlDatabase::addDatabase("QSQLITE");

    if (!QDir(dbFolder).exists())
        QDir().mkdir(dbFolder);

    dbConnection.setDatabaseName(dbFolder + "/database.db");
}

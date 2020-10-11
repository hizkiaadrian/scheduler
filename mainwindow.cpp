#include "mainwindow.h"
#include "./ui_mainwindow.h"

#include "newcategorydialog.h"
#include "neweventdialog.h"
#include "settingsdialog.h"

#include <QInputDialog>
#include <QDir>
#include <QString>
#include <QSqlQuery>
#include <QSqlDatabase>
#include <QStandardPaths>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    this->connectToDatabase();

    if (dbConnection.open()) {
        QSqlQuery sqlQuery(dbConnection);
        if (!sqlQuery.exec("CREATE TABLE IF NOT EXISTS categories("
                           "category_id INTEGER PRIMARY KEY AUTOINCREMENT,"
                           "name TEXT NOT NULL UNIQUE);"))
            ui->statusbar->showMessage("Failed to create Category database");
    }

}


MainWindow::~MainWindow()
{
    delete ui;

}

void MainWindow::connectToDatabase()
{
    this->dbConnection = QSqlDatabase::addDatabase("QSQLITE");

    QString appDataLocation = QStandardPaths::writableLocation(QStandardPaths::AppDataLocation);

    if (!QDir(appDataLocation).exists())
        QDir().mkdir(appDataLocation);

    dbConnection.setDatabaseName(appDataLocation + "/database.db");

    ui->statusbar->showMessage(dbConnection.open()
                               ? "Connected to database"
                               : "Failed to connect to database");
}

void MainWindow::createCategoryTable(QSqlDatabase dbConnection)
{
    QSqlQuery sqlQuery(dbConnection);
    if (!sqlQuery.exec("CREATE TABLE IF NOT EXISTS categories("
                       "category_id INTEGER PRIMARY KEY AUTOINCREMENT,"
                       "name TEXT NOT NULL UNIQUE);"))
        ui->statusbar->showMessage("Failed to create Category database");
}


void MainWindow::on_actionEvent_triggered()
{
    NewEventDialog newEventDialog(this->dbConnection);
    newEventDialog.exec();

}


void MainWindow::on_actionEvent_Category_triggered()
{
//    bool ok;
//    QString newCategoryName = QInputDialog::getText(this,
//                                         tr("Add a new event category"),
//                                         tr("Category name:"),
//                                         QLineEdit::Normal,
//                                         QDir::home().dirName(),
//                                         &ok);

    NewCategoryDialog newCategoryDialog(this->dbConnection);
    newCategoryDialog.exec();

//    if (ok && !newCategoryName.isEmpty()) {
//        QSqlQuery sqlQuery(dbConnection);
//        sqlQuery.prepare("INSERT INTO categories (name)"
//                                      "VALUES (?);");
//        sqlQuery.bindValue(0, newCategoryName);
//        bool inserted = sqlQuery.exec();

//        ui->statusbar->showMessage(inserted
//                                   ? "Category " + newCategoryName + " added successfully"
//                                   : "Failed to add category to database");
//    }

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

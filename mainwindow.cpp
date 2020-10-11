#include "mainwindow.h"
#include "./ui_mainwindow.h"
//#include "settingsdialog.h"
#include "neweventdialog.h"
#include "newcategorydialog.h"

#include <QInputDialog>
#include <QDir>
#include <QString>
#include <QSqlQuery>
#include <QSqlDatabase>
#include <QStandardPaths>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , dbPath(QStandardPaths::writableLocation(QStandardPaths::AppDataLocation) + "/database.db")
{
    ui->setupUi(this);

    this->dbConnection = QSqlDatabase::addDatabase("QSQLITE");
    dbConnection.setDatabaseName(dbPath);

    if (!QDir(QStandardPaths::writableLocation(QStandardPaths::AppDataLocation)).exists())
        QDir().mkdir(QStandardPaths::writableLocation(QStandardPaths::AppDataLocation));

    ui->statusbar->showMessage(dbConnection.open()
                               ? "Connected to " + dbPath
                               : "Failed to connect to database");

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
//    SettingsDialog settingsDialog;
//    settingsDialog.exec();

}


void MainWindow::on_actionExit_triggered()
{
    QApplication::quit();

}

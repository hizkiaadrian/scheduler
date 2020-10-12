#include "utils.h"
#include <QDir>

void connectToDatabase(QString dbFolder, QSqlDatabase &dbConnection)
{
    dbConnection = QSqlDatabase::addDatabase("QSQLITE");

    if (!QDir(dbFolder).exists())
        QDir().mkdir(dbFolder);

    dbConnection.setDatabaseName(dbFolder + "/database.db");

}

void showMessage(QLabel* label, QString text, MessageType messageType) {
    switch (messageType) {
    case MessageError:
        label->setStyleSheet("color:red");
        break;

    case MessageInfo:
        label->setStyleSheet("color:cyan");
        break;

    case MessageWarn:
        label->setStyleSheet("color:yellow");
        break;

    case MessageOK:
        label->setStyleSheet("color: green");
        break;
    }

    label->setText(text);
}

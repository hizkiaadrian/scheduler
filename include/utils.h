#pragma once

#include <QString>
#include <QSqlDatabase>
#include <QLabel>

#include "messagetype.h"

void connectToDatabase(QString dbFolder, QSqlDatabase &dbConnection);

void showMessage(QLabel* label, QString text, MessageType messageType);

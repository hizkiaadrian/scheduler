#include "mainwindow.h"

#include <QApplication>
#include <QSqlDatabase>
#include <QDir>
#include <QStandardPaths>

const QString dbPath = QStandardPaths::writableLocation(QStandardPaths::AppDataLocation) + "/database.db";

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    MainWindow window;
    window.show();
    return app.exec();
}

#include <QApplication>
#include <QSqlDatabase>

#include "widgets/mainwindow.h"


QSqlDatabase* dbConnectionPtr;

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    MainWindow window;
    window.show();
    return app.exec();
}

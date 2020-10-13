#include <QApplication>
#include <QSqlDatabase>

#include "widgets/mainwindow.h"

MainWindow* mainWindowPtr;
QSqlDatabase* dbConnectionPtr;

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    MainWindow window;
    mainWindowPtr = &window;
    window.show();
    return app.exec();
}

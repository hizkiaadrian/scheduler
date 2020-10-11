#pragma once

#include <QMainWindow>
#include <QString>
#include <QSqlDatabase>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_actionEvent_triggered();

    void on_actionEvent_Category_triggered();

    void on_actionSettings_triggered();

    void on_actionExit_triggered();

private:
    Ui::MainWindow *ui;
    const QString dbPath;
    QSqlDatabase dbConnection;
};

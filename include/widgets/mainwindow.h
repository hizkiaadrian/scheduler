#pragma once

#include <QMainWindow>
#include <QSqlDatabase>

namespace Ui { class MainWindow; }

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

    void setStatusBarText(const QString&);

private:
    Ui::MainWindow *ui;
    QSqlDatabase dbConnection;
};

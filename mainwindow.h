#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include"battlewindow.h"
#include"battle.h"
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    battle *battlescene;

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H

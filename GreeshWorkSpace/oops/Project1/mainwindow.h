#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "ProductCar.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    ProductCar* carFactory;
    Car* pBenz;
    Car* pBmw;
    Car* pAudi;
    void onClicked();
};

#endif // MAINWINDOW_H

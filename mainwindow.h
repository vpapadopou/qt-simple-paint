#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <iostream>
#include <QMainWindow>
#include <QAbstractButton>
#include "canvaswidget.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void colorSelectGroup_clicked(QAbstractButton* button);

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H

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

    void on_brushSize_slider_sliderReleased();
    void on_brushSize_slider_sliderMoved(int position);
    void on_brushSize_slider_valueChanged(int value);

    void on_clearAll_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H

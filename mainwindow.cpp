#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //Set number button group listener
    ui->colorSelectGroup->connect(ui->colorSelectGroup, SIGNAL(buttonClicked(QAbstractButton*)),
                             this, SLOT(colorSelectGroup_clicked(QAbstractButton*)));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::colorSelectGroup_clicked(QAbstractButton* button)
{

    QString buttonName = button->objectName();

    //Default color - black
    QColor selectedColor = Qt::black;

    //Set color according to button name
    if (buttonName == "color_red") {
        selectedColor = Qt::red;
    }
    else if (buttonName == "color_blue") {
        selectedColor = Qt::blue;
    }
    else if (buttonName == "color_green") {
        selectedColor = Qt::green;
    }
    else if (buttonName == "color_yellow") {
        selectedColor = Qt::yellow;
    }
    else if (buttonName == "color_grey") {
        selectedColor = Qt::gray;
    }
    else if (buttonName == "color_white") {
        selectedColor = Qt::white;
    }
    //Call appropriate method
    ui->canvasWidget->setColor(selectedColor);

}

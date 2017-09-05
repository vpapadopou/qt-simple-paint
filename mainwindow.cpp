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
    //Set default brush size label
    ui->brushSize_label->setText("5");
}

MainWindow::~MainWindow()
{
    delete ui;
}

//============================================================
//Color method
//============================================================
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

//============================================================
//Slider methods
//============================================================
void MainWindow::on_brushSize_slider_sliderReleased()
{
    //Call appropriate method to set brush size
    ui->canvasWidget->setBrushSize(ui->brushSize_slider->value());
}

void MainWindow::on_brushSize_slider_sliderMoved(int position)
{
    ui->brushSize_label->setText(QString::number(position));
}

void MainWindow::on_brushSize_slider_valueChanged(int value)
{
    ui->brushSize_label->setText(QString::number(value));
    ui->canvasWidget->setBrushSize(value);

}

//============================================================
//Various methods
//============================================================
void MainWindow::on_clearAll_clicked()
{
    ui->canvasWidget->clearAll();
}

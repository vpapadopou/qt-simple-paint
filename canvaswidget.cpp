#include "canvaswidget.h"

CanvasWidget::CanvasWidget(QWidget *parent) : QWidget(parent)
{

    canvasImage = QImage(this->size(), QImage::Format_RGB32);

    canvasImage.fill(Qt::white);
    drawingActive = false;
    currentColor = Qt::black;
}


CanvasWidget::~CanvasWidget()
{

}

void CanvasWidget::test1() {
    std::cout << "yup" << std::endl;
}

//=========================================================
//Mouse event methods
//=========================================================
void CanvasWidget::mousePressEvent(QMouseEvent *event)
{
    //Check if the button mouse that was clicked was the left one
    if (event->button() == Qt::LeftButton)
    {
        //Save last mouse point
        latestPoint = event->pos();
        //Raise flag to indicate that we are currently drawing something
        drawingActive = true;
    }
}

void CanvasWidget::mouseMoveEvent(QMouseEvent *event)
{
    //Check again if the left mouse button was clicked and whether we are drawing something
    if ((event->buttons() & Qt::LeftButton) && drawingActive)
    {
        //Create a new painter
        QPainter painter(&canvasImage);
        //Set parameters according to settings (hard-coded for now)
        painter.setPen(QPen(currentColor, 5, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin));
        //Draw line
        painter.drawLine(latestPoint, event->pos());
        //Save last point
        latestPoint = event->pos();
        //Update canvas
        this->update();
    }
}

void CanvasWidget::mouseReleaseEvent(QMouseEvent *event)
{
    //When the left mouse button is released, set the flag to false
    if (event->button() == Qt::LeftButton)
    {
        drawingActive = false;
    }
}

//=========================================================
//Draw method
//=========================================================
void CanvasWidget::paintEvent(QPaintEvent *event)
{
    QPainter canvasPainter(this);
    canvasPainter.drawImage(this->rect(), canvasImage, canvasImage.rect());
}

//=========================================================
//Resize method
//=========================================================
void CanvasWidget::resizeEvent(QResizeEvent *event)
{
    //On resize delete everything (not an optimal solution to be true...)
    canvasImage = QImage(this->size(), QImage::Format_RGB32);
    canvasImage.fill(Qt::white);
}

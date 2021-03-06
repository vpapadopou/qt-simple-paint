#ifndef CANVASWIDGET_H
#define CANVASWIDGET_H

#include <QWidget>
#include <QPainter>
#include <QMouseEvent>

class CanvasWidget : public QWidget
{
    Q_OBJECT
public:
    explicit CanvasWidget(QWidget *parent = nullptr);
    ~CanvasWidget();

    virtual void mousePressEvent(QMouseEvent *event);
    virtual void mouseMoveEvent(QMouseEvent *event);
    virtual void mouseReleaseEvent(QMouseEvent *event);
    virtual void paintEvent(QPaintEvent *event);
    virtual void resizeEvent(QResizeEvent *event);

    void setColor(QColor selectedColor);
    void setBrushSize(int selectedSize);
    void clearAll();

    QImage getImage();

private:
    //Canvas
    QImage canvasImage;
    //Flag to indicate whether we are currently drawing something (used on mouse events)
    bool drawingActive;
    //Latest mouse point
    QPoint latestPoint;
    //Color variable
    QColor currentColor;
    //Brush size variable
    int brushSize;
};

#endif // CANVASWIDGET_H

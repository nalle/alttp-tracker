#include "button.h"

QButton::QButton(QWidget *parent) : QPushButton(parent) {}

void QButton::mousePressEvent(QMouseEvent *e) {
    if(e->button()==Qt::RightButton)
        emit rightClicked();
    if(e->button()==Qt::LeftButton)
        emit clicked();
}

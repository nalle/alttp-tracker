#ifndef QBUTTONBUTTON_H
#define QBUTTONBUTTON_H

#include <QPushButton>
#include <QMouseEvent>

class QButton : public QPushButton {
    Q_OBJECT
    public:
        explicit QButton(QWidget *parent = 0);

    private slots:
        void mousePressEvent(QMouseEvent *e);

    signals:
        void rightClicked();

    public slots:
};

#endif // QBUTTONBUTTON_H

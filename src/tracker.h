#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QCoreApplication>
#include <QPushButton>
#include <QLabel>
#include <QDebug>
namespace Ui {
   class MainWindow;
}

using namespace std;
class TrackerObject: public QMainWindow {
    Q_OBJECT
    public:
        #ifdef Q_OS_LINUX
            QString image_path="/usr/share/tracker/images/";
        #else
            QString image_path="c:\\tmp\\images\\";
        #endif
        int x, y = 0;
        unsigned int itemcount = 0;
        bool toggled = false;
        array<QString, 4> images = {};
        QPushButton *button;
        QLabel *icon;

    QString image() {
        return this->images[this->itemcount];
    }

    QString next_image() {
        if ( this->itemcount == (sizeof(this->images) / 8 ) - 1 ) {
            this->itemcount = 0;
        } else {
            this->itemcount++;
        }

        if (this->images[this->itemcount].length() == 0) {
            this->itemcount = 0;
        }
        return this->image_path+this->image();
    }

    void setupObject(int x, int y) {
        this->x = x;
        this->y = y;
        this->icon->setPixmap(this->image_path+this->image());
        this->icon->setGeometry(QRect(QPoint(this->x, this->y),QSize(62, 62)));
        this->button->setGeometry(QRect(QPoint(this->x, this->y),QSize(62, 62)));
        this->button->setStyleSheet("background-color: rgba(0,0,0,60%); color: white; border: 0;");
    }
};


class Item: public TrackerObject {
};

class MainWindow : public QMainWindow {
    Q_OBJECT
    public:
        explicit MainWindow(QWidget *parent = 0);
    public slots:
        bool toggle(Item *item);
        void progress(Item *item);
        bool enable_item(Item *item);
        bool disable_item(Item *item);
};


#endif // MAINWINDOW_H

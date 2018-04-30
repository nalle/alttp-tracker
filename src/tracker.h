#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "button.h"
#include <QMouseEvent>
#include <QMainWindow>
#include <QPushButton>
#include <QCoreApplication>
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
        bool is_dungeon, is_medallion = false;
        array<QString, 4> images = {};
        array<QString, 4> dungeon_images = {"crystal1.png", "crystal2.png", "pendant1.png", "pendant2.png" };
        array<QString, 3> medallion_images = { "medallion_tr1.png", "medallion_mm1.png", "medallion_both.png" };
        QButton *button;
        QLabel *icon;
        QLabel *dungeon;
        QLabel *medallion;

    QString image() {
        return this->images[this->itemcount];
    }

    QString dungeon_image() {
        return this->dungeon_images[this->itemcount];
    }

    QString medallion_image() {
        return this->medallion_images[this->itemcount];
    }

    QString next_medallion_image() {
        if ( this->itemcount == (sizeof(this->medallion_images) / 8 ) - 1 ) {
            this->itemcount = 0;
        } else {
            this->itemcount++;
        }

        if (this->medallion_images[this->itemcount].length() == 0) {
            this->itemcount = 0;
        }
        return this->image_path+this->medallion_image();
    }

    QString next_dungeon_image() {
        if ( this->itemcount == (sizeof(this->dungeon_images) / 8 ) - 1 ) {
            this->itemcount = 0;
        } else {
            this->itemcount++;
        }

        if (this->dungeon_images[this->itemcount].length() == 0) {
            this->itemcount = 0;
        }
        return this->image_path+this->dungeon_image();
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
        this->icon->setStyleSheet("background-color: rgba(0,0,0,0%); color: white; border: 0;");

        if (this->is_dungeon) { 
            this->dungeon->setGeometry(QRect(QPoint(this->x, this->y),QSize(62, 62)));
            delete this->medallion;
        } else {
            delete this->dungeon;
        }
/*
        if (this->is_medallion) {
            this->medallion->setGeometry(QRect(QPoint(this->x, this->y),QSize(62, 62)));
            delete this->dungeon;
        } else {
            delete this->medallion;
        }
*/
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
        void progress_dungeon(Item *item);
        void progress_medallion(Item *item);
        bool enable_item(Item *item);
        bool disable_item(Item *item);
};


#endif // MAINWINDOW_H

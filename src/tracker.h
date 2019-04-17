#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <cmath>
#include "button.h"
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
        QString img_path="/usr/share/tracker/images/";
        QButton *button;
        QLabel *overlay;
        QLabel *label;
        QString name, short_name;
        bool toggled = false;
        int images = 1;
        int currentimage = 0;
        float fontsize = 24;
        float x;
        float y;

    void Progress() {
        if (this->toggled) {
            if (this->currentimage < this->images) {
                this->currentimage++;
                this->button->setStyleSheet("background-color: rgba(0,0,0,0%); color: white; border: 0; outline: none;");
            } else {
                this->currentimage = 0;
                this->button->setStyleSheet("background-color: rgba(0,0,0,60%); color: white; border: 0; outline: none;");
                this->toggled ^= true;
            }
        } else {
            this->button->setStyleSheet("background-color: rgba(0,0,0,0%); color: white; border: 0; outline: none;");
            this->toggled ^= true;
        }
        if (this->images > 0) {
            QPixmap img(img_path+name+QString::number(currentimage)+".png"); 
            this->label->setPixmap(img);
        }
    }
    void Toggle() {
        if (this->toggled) {
            this->button->setStyleSheet("background-color: rgba(0,0,0,60%); color: white; border: 0;");
        } else {
            this->button->setStyleSheet("background-color: rgba(0,0,0,0%); color: white; border: 0;");
        }
        this->toggled ^= true;
    }
};

class Item: public TrackerObject {
    Q_OBJECT
    public:
        int currentmedallion = 0;
        bool ticked = true;

    void ProgressMedallion() {
        QList<QString> images = { "", img_path+"medallion_mm1.png", img_path+"medallion_tr1.png", img_path+"medallion_both.png" }; 

        if (currentmedallion >= images.length()-1) {
            currentmedallion = 0;
        } else {
            currentmedallion++;
        }
        QPixmap img(images[this->currentmedallion]);
        this->overlay->setStyleSheet("background-color: rgba(0,0,0,0%); color: white; border: 0;");
        this->overlay->setPixmap(img.scaled(64, 64, Qt::KeepAspectRatio));
    }

    void Tick() {
        QPixmap img(img_path+"checkmark.png");
        QPixmap noimg("");
        this->overlay->setStyleSheet("background-color: rgba(0,0,0,0%); color: white; border: 0;");

        if (this->ticked == false) {
            this->overlay->setPixmap(img);
        } else {
            this->overlay->setPixmap(noimg);
        }

        this->ticked ^= true;
    }

    Item(QWidget *widget, QString name, int x, int y) {
        this->name = name;
        this->ticked = false;
        this->x = x;
        this->y = y;

        QPixmap img(img_path+name+"0.png");
        this->label = new QLabel(widget);
        this->overlay = new QLabel(widget);
        this->button = new QButton(widget);
        this->overlay->setGeometry(QRect(QPoint(x, y),QSize(64, 64)));
        this->overlay->setStyleSheet("background-color: rgba(0,0,0,0%); color: white; border: 0;");
        this->label->setPixmap(img.scaled(64, 64, Qt::KeepAspectRatio));
        this->label->setGeometry(QRect(QPoint(x, y),QSize(64, 64)));
        this->label->setStyleSheet("background-color: rgba(0,0,0,0%); color: white; border: 0;");
        this->button->setGeometry(QRect(QPoint(x, y),QSize(64, 64)));
        this->button->setStyleSheet("background-color: rgba(0,0,0,60%); color: white; border: 0; outline: none;");
    }
    

};

class Dungeon: public TrackerObject {
    Q_OBJECT
    public:

    Dungeon(QWidget *widget, QString name, QString short_name, int x, int y) {
        this->name = name;
        this->short_name = short_name;
        this->x = x;
        this->y = y;


        QPixmap img(img_path+name+"0.png");
        this->label = new QLabel(widget);
        this->label->setText(short_name);
        this->label->setGeometry(QRect(QPoint(x, y),QSize(52, 30)));
        this->label->setStyleSheet("background-color: rgba(0,0,0,0%); color: white; border: 0;outline: none;font-weight: bold; font-size: "+QString::number(round(fontsize))+"px");
    }
};

class DungeonType: public TrackerObject {
    Q_OBJECT
    public:
        int currentimage = 0;
        QList<QString> images = { img_path+"questionmark.png", img_path+"crystal.png", img_path+"crystal-red.png", img_path+"pendant.png", img_path+"pendant-green.png" };

    DungeonType(QWidget *widget, QString name, int x, int y) {
        this->name = name;
        this->x = x;
        this->y = y;

        QPixmap img(img_path+"questionmark.png");
        this->label = new QLabel(widget);
        this->button = new QButton(widget);
        this->label->setPixmap(img.scaled(20,36,Qt::KeepAspectRatio));
        this->label->setGeometry(QRect(QPoint(x, y),QSize(48, 30)));
        this->label->setStyleSheet("background-color: rgba(0,0,0,0%); color: white; border: 0;");
        this->button->setGeometry(QRect(QPoint(x, y),QSize(48, 30)));
        this->button->setStyleSheet("background-color: rgba(0,0,0,60%); color: white; border: 0; outline: none;");
    }
    
    void Progress() {
        if (this->currentimage < this->images.length()-1) {
            this->currentimage++;
        } else {
            this->currentimage = 0;
            this->toggled ^= true;
        }

        QPixmap img(this->images[this->currentimage]);
        this->label->setPixmap(img.scaled(20,36,Qt::KeepAspectRatio));
    }
};

class Bigkey: public TrackerObject {
    Q_OBJECT
    public:

    Bigkey(QWidget *widget, QString name, int x, int y) {
        this->name = name;
        this->x = x;
        this->y = y;


        QPixmap img(img_path+"bigkey.png");
        this->label = new QLabel(widget);
        this->button = new QButton(widget);
        this->label->setPixmap(img.scaled(38,38,Qt::KeepAspectRatio));
        this->label->setGeometry(QRect(QPoint(x, y),QSize(48, 30)));
        this->label->setStyleSheet("background-color: rgba(0,0,0,0%); color: white; border: 0;");
        this->button->setGeometry(QRect(QPoint(x, y),QSize(48, 30)));
        this->button->setStyleSheet("background-color: rgba(0,0,0,60%); color: white; border: 0; outline: none;");
    }
};

class Smallkey: public TrackerObject {
    Q_OBJECT
    public:
        QString textcolor = "white";

    Smallkey(QWidget *widget, QString name, int x, int y) {
        this->name = name;
        this->x = x;
        this->y = y;


        this->label = new QLabel(widget);
        this->button = new QButton(widget);
        this->label->setText("0");
        this->label->setGeometry(QRect(QPoint(x, y),QSize(48, 30)));
        this->label->setStyleSheet("background-color: rgba(0,0,0,0%); color: white; border: 0;outline: none;font-weight: bold; font-size: "+QString::number(round(fontsize))+"px");
        this->button->setGeometry(QRect(QPoint(x, y),QSize(48, 30)));
        this->button->setStyleSheet("background-color: rgba(0,0,0,0%); color: white; border: 0; outline: none;");
    }

    void Progress() {
        if (this->currentimage < this->images) {
            this->currentimage++;
        } else {
            this->currentimage = 0;
        }
        if (this->currentimage == this->images) {
            textcolor = "green";
        } else {
            textcolor = "white";
        }

        this->label->setStyleSheet("background-color: rgba(0,0,0,0%); color: "+textcolor+"; border: 0;outline: none;font-weight: bold; font-size: "+QString::number(round(fontsize))+"px");
        if (this->images > 0) {
            this->label->setText(QString::number(currentimage));
        }
    }

    void Toggle() {
        if (this->toggled) {
            this->button->setStyleSheet("background-color: rgba(0,0,0,60%); color: white; border: 0;outline: none;");
        } else {
            this->button->setStyleSheet("background-color: rgba(0,0,0,0%); color: white; border: 0;outline: none;");
        }
        this->toggled ^= true;
    }

};

class MainWindow : public QMainWindow {
    Q_OBJECT
    public:
        explicit MainWindow(QWidget *parent = 0);
        void RedrawTracker();
        void Resize(float scale = 1);
        QList<Item *> item_objects;
        QList<Smallkey *> smallkey_objects;
        QList<Bigkey *> bigkey_objects;
        QList<DungeonType *> dungeontype_objects;
        QList<Dungeon *> dungeon_objects;
    protected:
        void resizeEvent(QResizeEvent *event) override;

};


#endif // MAINWINDOW_H

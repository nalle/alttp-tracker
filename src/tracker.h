#ifndef MAINWINDOW_H
#define MAINWINDOW_H

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
        QButton *button;
        QLabel *overlay;
        QLabel *label;
        QString name;
        bool toggled = false;
        int images = 1;
        int currentimage = 1;

    void Progress() {
        qDebug() << "Progressing item";
        if (this->toggled) {
            if (this->currentimage >= this->images) {
                this->currentimage = 1;
                this->button->setStyleSheet("background-color: rgba(0,0,0,60%); color: white; border: 0; outline: none;");
                this->toggled ^= true;
            } else {
                this->currentimage++;
                this->button->setStyleSheet("background-color: rgba(0,0,0,0%); color: white; border: 0; outline: none;");
            }
        } else {
            this->button->setStyleSheet("background-color: rgba(0,0,0,0%); color: white; border: 0; outline: none;");
            this->toggled ^= true;
        }
        QPixmap img("/usr/share/tracker/images/"+name+QString::number(currentimage)+".png"); 
        if (this->images > 1) {
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

    void ProgressMedallion() {
        QList<QString> images = { "", "/usr/share/tracker/images/medallion_mm1.png", "/usr/share/tracker/images/medallion_tr1.png", "/usr/share/tracker/images/medallion_both.png" }; 

        if (currentmedallion >= images.length()-1) {
            currentmedallion = 0;
        } else {
            currentmedallion++;
        }
        QPixmap img(images[this->currentmedallion]);
        this->overlay->setStyleSheet("background-color: rgba(0,0,0,0%); color: white; border: 0;");
        this->overlay->setPixmap(img);
    }

    Item(QWidget *widget, QString name, int x, int y) {
        this->name = name;

        QString img = "/usr/share/tracker/images/"+name+"1.png";
        this->label = new QLabel(widget);
        this->overlay = new QLabel(widget);
        this->button = new QButton(widget);
        this->overlay->setGeometry(QRect(QPoint(x, y),QSize(64, 64)));
        this->overlay->setStyleSheet("background-color: rgba(0,0,0,0%); color: white; border: 0;");
        this->label->setPixmap(img);
        this->label->setGeometry(QRect(QPoint(x, y),QSize(64, 64)));
        this->label->setStyleSheet("background-color: rgba(0,0,0,0%); color: white; border: 0;");
        this->button->setGeometry(QRect(QPoint(x, y),QSize(64, 64)));
        this->button->setStyleSheet("background-color: rgba(0,0,0,60%); color: white; border: 0; outline: none;");
    }
    

};

class Dungeon: public TrackerObject {
    Q_OBJECT
    public:

    Dungeon(QWidget *widget, QString name, int x, int y) {
        this->name = name;

        QPixmap img("/usr/share/tracker/images/"+name+"1.png");
        this->label = new QLabel(widget);
        this->label->setPixmap(img);
        this->label->setGeometry(QRect(QPoint(x, y),QSize(48, 30)));
        this->label->setStyleSheet("background-color: rgba(0,0,0,0%); color: white; border: 0;outline: none;");
    }
};

class DungeonType: public TrackerObject {
    Q_OBJECT
    public:

    DungeonType(QWidget *widget, QString name, int x, int y) {
        this->name = name;

        QPixmap img("/usr/share/tracker/images/questionmark.png");
        this->label = new QLabel(widget);
        this->button = new QButton(widget);
        this->label->setPixmap(img.scaled(15,36,Qt::KeepAspectRatio));
        this->label->setGeometry(QRect(QPoint(x, y),QSize(48, 30)));
        this->label->setStyleSheet("background-color: rgba(0,0,0,0%); color: white; border: 0;");
        this->button->setGeometry(QRect(QPoint(x, y),QSize(48, 30)));
        this->button->setStyleSheet("background-color: rgba(0,0,0,60%); color: white; border: 0; outline: none;");
    }
    
    void Progress() {
        QList<QString> images = { "/usr/share/tracker/images/questionmark.png", "/usr/share/tracker/images/crystal.png", "/usr/share/tracker/images/crystal-red.png", "/usr/share/tracker/images/pendant.png", "/usr/share/tracker/images/pendant-green.png" };
        
        if (this->currentimage >= images.length()) {
            this->currentimage = 1;
            this->toggled ^= true;
        } else {
            this->currentimage++;
        }
        QPixmap img(images[this->currentimage-1]);
        this->label->setPixmap(img.scaled(15,36,Qt::KeepAspectRatio));
    }
};

class Bigkey: public TrackerObject {
    Q_OBJECT
    public:

    Bigkey(QWidget *widget, QString name, int x, int y) {
        this->name = name;

        QPixmap img("/usr/share/tracker/images/bigkey.png");
        this->label = new QLabel(widget);
        this->button = new QButton(widget);
        this->label->setPixmap(img.scaled(30,30,Qt::KeepAspectRatio));
        this->label->setGeometry(QRect(QPoint(x, y),QSize(48, 30)));
        this->label->setStyleSheet("background-color: rgba(0,0,0,0%); color: white; border: 0;");
        this->button->setGeometry(QRect(QPoint(x, y),QSize(48, 30)));
        this->button->setStyleSheet("background-color: rgba(0,0,0,60%); color: white; border: 0; outline: none;");
    }
};

class Smallkey: public TrackerObject {
    Q_OBJECT
    public:

    Smallkey(QWidget *widget, QString name, int x, int y) {
        this->name = name;

        QPixmap img("/usr/share/tracker/images/number1.png");
        this->label = new QLabel(widget);
        this->button = new QButton(widget);
        this->label->setPixmap(img);
        this->label->setGeometry(QRect(QPoint(x, y),QSize(48, 30)));
        this->label->setStyleSheet("background-color: rgba(0,0,0,0%); color: white; border: 0;");
        this->button->setGeometry(QRect(QPoint(x, y),QSize(48, 30)));
        this->button->setStyleSheet("background-color: rgba(0,0,0,0%); color: white; border: 0; outline: none;");
    }
    void Progress() {
        if (this->currentimage >= this->images) {
            this->currentimage = 1;
        } else {
            this->currentimage++;
        }

        QPixmap img("/usr/share/tracker/images/"+name+QString::number(currentimage)+".png"); 
        this->label->setPixmap(img);
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
};

#endif // MAINWINDOW_H

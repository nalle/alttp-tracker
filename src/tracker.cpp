#include "tracker.h"
#include <QCoreApplication>
#include <QPushButton>
#include <QLabel>
#include <QMessageBox>
#include <QtDebug>
#include <QList>
#include <QtWidgets>


MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) {
    MainWindow::RedrawTracker();
}


void MainWindow::Resize(float scale) {
    for (int i = 0; i < item_objects.length(); i++) {
        QString currentimage = QString::number(item_objects[i]->currentimage);
        QPixmap img(item_objects[i]->img_path+item_objects[i]->name+currentimage+".png");
        item_objects[i]->label->setPixmap(img.scaled(img.height()*scale, img.width()*scale, Qt::KeepAspectRatio));
        item_objects[i]->button->setGeometry(QRect(QPoint(item_objects[i]->x*scale, item_objects[i]->y*scale),QSize(img.height()*scale, img.width()*scale)));
        item_objects[i]->label->setGeometry(QRect(QPoint(item_objects[i]->x*scale, item_objects[i]->y*scale),QSize(img.height()*scale, img.width()*scale)));
    }

    for (int i = 0; i < smallkey_objects.length(); i++) {
        smallkey_objects[i]->label->setText(QString::number(smallkey_objects[i]->currentimage));
        smallkey_objects[i]->button->setGeometry(QRect(QPoint(smallkey_objects[i]->x*scale, smallkey_objects[i]->y*scale),QSize(48*scale, 30*scale)));
        smallkey_objects[i]->label->setGeometry(QRect(QPoint(smallkey_objects[i]->x*scale, smallkey_objects[i]->y*scale),QSize(48*scale, 30*scale)));
        smallkey_objects[i]->label->setStyleSheet("background-color: rgba(0,0,0,0%); color: white; border: 0;outline: none;font-weight: bold; font-size: "+QString::number(round(24*scale))+"px");
    }

    for (int i = 0; i < bigkey_objects.length(); i++) {
        QPixmap img(bigkey_objects[i]->img_path+"bigkey.png");
        bigkey_objects[i]->label->setPixmap(img.scaled(48*scale, 30*scale, Qt::KeepAspectRatio));
        bigkey_objects[i]->button->setGeometry(QRect(QPoint(bigkey_objects[i]->x*scale, bigkey_objects[i]->y*scale),QSize(48*scale, 30*scale)));
        bigkey_objects[i]->label->setGeometry(QRect(QPoint(bigkey_objects[i]->x*scale, bigkey_objects[i]->y*scale),QSize(48*scale, 30*scale)));
    }

    for (int i = 0; i < dungeon_objects.length(); i++) {
        dungeon_objects[i]->label->setText(dungeon_objects[i]->short_name);
        dungeon_objects[i]->label->setGeometry(QRect(QPoint(dungeon_objects[i]->x*scale, dungeon_objects[i]->y*scale),QSize(52*scale, 30*scale)));
        dungeon_objects[i]->label->setStyleSheet("background-color: rgba(0,0,0,0%); color: white; border: 0;outline: none;font-weight: bold; font-size: "+QString::number(round(24*scale))+"px");
    }

    for (int i = 0; i < dungeontype_objects.length(); i++) {
        int currentimage = dungeontype_objects[i]->currentimage;
        QPixmap img(dungeontype_objects[i]->images[currentimage]);
        dungeontype_objects[i]->label->setPixmap(img.scaled(img.height()*scale, img.width()*scale, Qt::KeepAspectRatio));
        dungeontype_objects[i]->button->setGeometry(QRect(QPoint(dungeontype_objects[i]->x*scale, dungeontype_objects[i]->y*scale),QSize(48*scale, 30*scale)));
        dungeontype_objects[i]->label->setGeometry(QRect(QPoint(dungeontype_objects[i]->x*scale, dungeontype_objects[i]->y*scale),QSize(48*scale, 30*scale)));
    }
}

void MainWindow::RedrawTracker() { 
    QList<QString> dungeons = { "easternpalace", 
                                "desertpalace",
                                "towerofhera",
                                "agahnimstower",
                                "hyrulecastle",
                                "palaceofdarkness",
                                "swamppalace",
                                "skullwoods",
                                "thievestown",
                                "icepalace",
                                "miserymire",
                                "turtlerock",
                                "ganonstower"
                            };
    QList<QString> dungeons_shortname = { "EP", 
                                "DP",
                                "TOH",
                                "AT",
                                "HC",
                                "POD",
                                "SP",
                                "SW",
                                "TT",
                                "IP",
                                "MM",
                                "TR",
                                "GT"
                            };

    QList<QString> items = { "bow", 
                             "boomerang", 
                             "hookshot", 
                             "mushroom", 
                             "powder", 
                             "firerod", 
                             "icerod", 
                             "bombos", 
                             "ether", 
                             "quake", 
                             "lamp", 
                             "hammer", 
                             "flute", 
                             "shovel", 
                             "book", 
                             "bottle", 
                             "somaria", 
                             "byrna", 
                             "cape", 
                             "mirror", 
                             "boots", 
                             "gloves",
                             "flippers", 
                             "moonpearl", 
                             "bugnet", 
                             "sword", 
                             "shield", 
                             "tunic", 
                             "halfmagic", 
                             "aghanim" 
                           };
    QList<int> item_images = {2,1,0,0,0,0,0,0,0,0,0,0,0,0,0,3,0,0,0,0,0,1,0,0,0,3,2,2,0,0};
    QList<int> smallkey_images = {0,1,1,2,1,6,1,3,1,2,3,4,4};

    int gridsize = 64;
   
    int x = 0;
    int y = 0;

    /* Draw items */
    for (int i = 0; i < items.length(); i++) {
        item_objects.append(new Item(this, items[i], x, y));
        item_objects[i]->images = item_images[i];
        connect(item_objects[i]->button, &QButton::clicked, [=]{
            item_objects[i]->Progress();
        });
        if (item_objects[i]->name == "bombos" || item_objects[i]->name == "ether" || item_objects[i]->name == "quake") {
            connect(item_objects[i]->button, &QButton::rightClicked, [=]{
                item_objects[i]->ProgressMedallion();
            });
        }

        if (item_objects[i]->name == "mushroom" || item_objects[i]->name == "powder" || item_objects[i]->name == "shovel" || item_objects[i]->name == "flute") {
            connect(item_objects[i]->button, &QButton::rightClicked, [=]{
                item_objects[i]->Tick();
            });
        }

        x += gridsize;
        if (x / gridsize == 5) { 
            y += gridsize;
            x = 0;
        }
    }   
    x = gridsize*5;
    y = 0;
    
    /* Draw dungeons */
    for (int i = 0; i < dungeons.length(); i++) {
        dungeon_objects.append(new Dungeon(this, dungeons[i], dungeons_shortname[i], x, y));
        y += 30;
    }
    x = gridsize*6;
    y = 0;

    /* Draw crystal / pendants */
    for (int i = 0; i < dungeons.length(); i++) {
        if (dungeons[i] == "hyrulecastle" || dungeons[i] == "agahnimstower" || dungeons[i] == "ganonstower") {
            dungeontype_objects.append(new DungeonType(this, dungeons[i], x+1000, y+1000));
        } else {
            dungeontype_objects.append(new DungeonType(this, dungeons[i], x, y));
            connect(dungeontype_objects[i]->button, &QPushButton::clicked, [=]{
                dungeontype_objects[i]->Toggle();
            });

            connect(dungeontype_objects[i]->button, &QButton::rightClicked, [=]{
                dungeontype_objects[i]->Progress();
            });
        }

        y += 30;
    }

    x = gridsize*6.4;
    y = 0;

    /* Draw bigkeys */
    for (int i = 0; i < dungeons.length(); i++) {
        if (dungeons[i] == "agahnimstower" || dungeons[i] == "hyrulecastle") {
            bigkey_objects.append(new Bigkey(this, dungeons[i], x+1000, y+1000));
        } else {
            bigkey_objects.append(new Bigkey(this, dungeons[i], x, y));
            connect(bigkey_objects[i]->button, &QPushButton::clicked, [=]{
                bigkey_objects[i]->Toggle();
            });
        }

        y += 30;
    }
    x = gridsize*7;
    y = 0;

    /* Draw small keys */
    for (int i = 0; i < dungeons.length(); i++) {
        if (dungeons[i] == "easternpalace") {        
            smallkey_objects.append(new Smallkey(this, "number", x+1000, y+1000));
        } else {
            smallkey_objects.append(new Smallkey(this, "number", x, y));
            smallkey_objects[i]->images = smallkey_images[i];
            connect(smallkey_objects[i]->button, &QPushButton::clicked, [=]{
                smallkey_objects[i]->Progress();
            });
        }

        y += 30;
    }

    /* default always hilight green tunic */
    item_objects[items.indexOf("tunic")]->Toggle();

}

void MainWindow::resizeEvent(QResizeEvent* event) {
    QMainWindow::resizeEvent(event);
    MainWindow::Resize((float)this->width()/(float)475);
}



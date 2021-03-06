#include "tracker.h"
#include <QCoreApplication>
#include <QPushButton>
#include <QLabel>
#include <QMessageBox>
#include <QtDebug>
#include <QList>

#define gridsize 64

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) {
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
    
    int x = 0;
    int y = 0;

    /* Draw items */
    QList<Item *> item_objects;
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
    QList<Dungeon *> dungeon_objects;
    for (int i = 0; i < dungeons.length(); i++) {
        dungeon_objects.append(new Dungeon(this, dungeons[i], dungeons_shortname[i], x, y));
        y += 30;
    }
    x = gridsize*6;
    y = 0;

    /* Draw crystal / pendants */
    QList<DungeonType *> dungeontype_objects;
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
    QList<Bigkey *> bigkey_objects;
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
    QList<Smallkey *> smallkey_objects;
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

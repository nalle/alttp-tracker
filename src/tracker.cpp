
#include "tracker.h"
#include <QCoreApplication>
#include <QIcon>
#include <QPushButton>
#include <QLabel>
#include <QMessageBox>
#include <QtDebug>
#include <QBitmap>
#include <QSignalMapper>

bool MainWindow::toggle(Item *item) {
    if (item->toggled) {
        enable_item(item);
    } else {
        disable_item(item);
    }
    item->toggled = !item->toggled;
    return true;
}

bool MainWindow::enable_item(Item *item) {
        item->button->setStyleSheet("background-color: rgba(0,0,0,0%); color: white; border: 0;");
        item->toggled = true;
        return item->toggled;
}

bool MainWindow::disable_item(Item *item) {
        item->button->setStyleSheet("background-color: rgba(0,0,0,60%); color: white; border: 0;");
        item->toggled = false;
        return item->toggled;
}

void MainWindow::progress(Item *item) {
    if (item->itemcount == 0 && !item->toggled) {
        enable_item(item);
        return;
    } else {
        item->icon->setPixmap(item->next_image());
    }
    if (item->itemcount == 0) {
        disable_item(item);
    }
}

void setupObject(Item *item, QWidget *widget, int x, int y, array<QString, 4> images) {
    item->images = images;
    item->icon = new QLabel(widget);
    item->button = new QPushButton("",widget);
    item->setupObject(x,y);
}

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) {
    Item *bow = new Item();
    setupObject(bow, this, 0, 0, { "bow1.png", "bow2.png", "bow3.png" });
    connect(bow->button, &QPushButton::released, [=]{
        progress(bow);
    });

    Item *boomerang = new Item();
    setupObject(boomerang, this, 62, 0, { "boomerang1.png","boomerang2.png" });
    connect(boomerang->button, &QPushButton::released, [=]{
        progress(boomerang);
    });

    Item *hookshot = new Item();
    setupObject(hookshot, this, 124, 0, { "hookshot1.png" });
    connect(hookshot->button, &QPushButton::released, [=]{
        toggle(hookshot);
    });

    Item *mushroom = new Item();
    setupObject(mushroom, this, 186, 0, { "mushroom1.png" });
    connect(mushroom->button, &QPushButton::released, [=]{
        toggle(mushroom);
    });

    Item *powder = new Item();
    setupObject(powder, this, 248, 0, { "powder1.png" });
    connect(powder->button, &QPushButton::released, [=]{
        toggle(powder);
    });

    Item *none0 = new Item();
    setupObject(none0, this, 310, 0, { "" });
    connect(none0->button, &QPushButton::released, [=]{
        toggle(none0);
    });

    Item *easternpalace = new Item();
    setupObject(easternpalace, this, 372, 0, { "easternpalace1.png" });
    connect(easternpalace->button, &QPushButton::released, [=]{
        toggle(easternpalace);
    });

    Item *firerod = new Item();
    setupObject(firerod, this, 0, 62, { "firerod1.png" });
    connect(firerod->button, &QPushButton::released, [=]{
        toggle(firerod);
    });

    Item *icerod = new Item();
    setupObject(icerod, this, 62, 62, { "icerod1.png" });
    connect(icerod->button, &QPushButton::released, [=]{
        toggle(icerod);
    });

    Item *bombos = new Item();
    setupObject(bombos, this, 124, 62, { "bombos1.png" });
    connect(bombos->button, &QPushButton::released, [=]{
        toggle(bombos);
    });

    Item *ether = new Item();
    setupObject(ether, this, 186, 62, { "ether1.png" });
    connect(ether->button, &QPushButton::released, [=]{
        toggle(ether);
    });

    Item *quake = new Item();
    setupObject(quake, this, 248, 62, { "quake1.png" });
    connect(quake->button, &QPushButton::released, [=]{
        toggle(quake);
    });

    Item *none1 = new Item();
    setupObject(none1, this, 310, 62, { "" });
    connect(none1->button, &QPushButton::released, [=]{
        toggle(none1);
    });

    Item *desertpalace = new Item();
    setupObject(desertpalace, this, 372, 62, { "desertpalace1.png" });
    connect(desertpalace->button, &QPushButton::released, [=]{
        toggle(desertpalace);
    });

    Item *lamp = new Item();
    setupObject(lamp, this, 0, 124, { "lamp1.png" });
    connect(lamp->button, &QPushButton::released, [=]{
        toggle(lamp);
    });

    Item *hammer = new Item();
    setupObject(hammer, this, 62, 124, { "hammer1.png" });
    connect(hammer->button, &QPushButton::released, [=]{
        toggle(hammer);
    });

    Item *flute = new Item();
    setupObject(flute, this, 124, 124, { "flute1.png" });
    connect(flute->button, &QPushButton::released, [=]{
        toggle(flute);
    });

    Item *shovel = new Item();
    setupObject(shovel, this, 186, 124, { "shovel1.png" });
    connect(shovel->button, &QPushButton::released, [=]{
        toggle(shovel);
    });

    Item *bugnet = new Item();
    setupObject(bugnet, this, 248, 124, { "bugnet1.png" });
    connect(bugnet->button, &QPushButton::released, [=]{
        toggle(bugnet);
    });

    Item *book = new Item();
    setupObject(book, this, 310, 124, { "book1.png" });
    connect(book->button, &QPushButton::released, [=]{
        toggle(book);
    });

    Item *towerofhera = new Item();
    setupObject(towerofhera, this, 372, 124, { "towerofhera1.png" });
    connect(towerofhera->button, &QPushButton::released, [=]{
        toggle(towerofhera);
    });

    Item *bottle = new Item();
    setupObject(bottle, this, 0, 186, { "bottle1.png","bottle2.png","bottle3.png","bottle4.png" });
    connect(bottle->button, &QPushButton::released, [=]{
        progress(bottle);
    });

    Item *caneofsomaria = new Item();
    setupObject(caneofsomaria, this, 62, 186, { "caneofsomaria1.png" });
    connect(caneofsomaria->button, &QPushButton::released, [=]{
        toggle(caneofsomaria);
    });

    Item *caneofbyrna = new Item();
    setupObject(caneofbyrna, this, 124, 186, { "caneofbyrna1.png" });
    connect(caneofbyrna->button, &QPushButton::released, [=]{
        toggle(caneofbyrna);
    });

    Item *cape = new Item();
    setupObject(cape, this, 186, 186, { "cape1.png" });
    connect(cape->button, &QPushButton::released, [=]{
        toggle(cape);
    });

    Item *mirror = new Item();
    setupObject(mirror, this, 248, 186, { "mirror1.png" });
    connect(mirror->button, &QPushButton::released, [=]{
        toggle(mirror);
    });

    Item *moonpearl = new Item();
    setupObject(moonpearl, this, 310, 186, { "moonpearl1.png" });
    connect(moonpearl->button, &QPushButton::released, [=]{
        toggle(moonpearl);
    });

    Item *aghanim = new Item();
    setupObject(aghanim, this, 372, 186, { "aghanim1.png" });
    connect(aghanim->button, &QPushButton::released, [=]{
        toggle(aghanim);
    });

    Item *boots = new Item();
    setupObject(boots, this, 0, 248, { "boots1.png" });
    connect(boots->button, &QPushButton::released, [=]{
        toggle(boots);
    });

    Item *gloves = new Item();
    setupObject(gloves, this, 62, 248, { "gloves1.png","gloves2.png" });
    connect(gloves->button, &QPushButton::released, [=]{
        progress(gloves);
    });

    Item *flippers = new Item();
    setupObject(flippers, this, 124, 248, { "flippers1.png" });
    connect(flippers->button, &QPushButton::released, [=]{
        toggle(flippers);
    });

    Item *halfmagic = new Item();
    setupObject(halfmagic, this, 186, 248, { "halfmagic1.png","halfmagic2.png" });
    connect(halfmagic->button, &QPushButton::released, [=]{
        toggle(halfmagic);
    });

    Item *shield = new Item();
    setupObject(shield, this, 248, 248, { "shield1.png","shield2.png","shield3.png" });
    connect(shield->button, &QPushButton::released, [=]{
        progress(shield);
    });

    Item *sword = new Item();
    setupObject(sword, this, 310, 248, { "sword1.png","sword2.png","sword3.png","sword4.png" });
    connect(sword->button, &QPushButton::released, [=]{
        progress(sword);
    });

    Item *tunic = new Item();
    setupObject(tunic, this, 372, 248, { "tunic1.png","tunic2.png","tunic3.png" });
    connect(tunic->button, &QPushButton::released, [=]{
        progress(tunic);
    });

    Item *palaceofdarkness = new Item();
    setupObject(palaceofdarkness, this, 0, 310, { "palaceofdarkness1.png" });
    connect(palaceofdarkness->button, &QPushButton::released, [=]{
        toggle(palaceofdarkness);
    });

    Item *swamppalace = new Item();
    setupObject(swamppalace, this, 62, 310, { "swamppalace1.png" });
    connect(swamppalace->button, &QPushButton::released, [=]{
        toggle(swamppalace);
    });

    Item *skullwoods = new Item();
    setupObject(skullwoods, this, 124, 310, { "skullwoods1.png" });
    connect(skullwoods->button, &QPushButton::released, [=]{
        toggle(skullwoods);
    });

    Item *thievestown = new Item();
    setupObject(thievestown, this, 186, 310, { "thievestown1.png" });
    connect(thievestown->button, &QPushButton::released, [=]{
        toggle(thievestown);
    });

    Item *icepalace = new Item();
    setupObject(icepalace, this, 248, 310, { "icepalace1.png" });
    connect(icepalace->button, &QPushButton::released, [=]{
        toggle(icepalace);
    });

    Item *miserymire = new Item();
    setupObject(miserymire, this, 310, 310, { "miserymire1.png" });
    connect(miserymire->button, &QPushButton::released, [=]{
        toggle(miserymire);
    });

    Item *turtlerock = new Item();
    setupObject(turtlerock, this, 372, 310, { "turtlerock1.png" });
    connect(turtlerock->button, &QPushButton::released, [=]{
        toggle(turtlerock);
    });
}

#include "tracker.h"
#include "ui_tracker.h"
#include <QAbstractButton>
#include <QDebug>

bool hookshotState = true;
bool mushroomState = true;
bool powderState = true;
bool firerodState = true;
bool icerodState = true;
bool bombosState = true;
bool etherState = true;
bool quakeState = true;
bool fullheartState = true;
bool lampState = true;
bool hammerState = true;
bool fluteState = true;
bool shovelState = true;
bool bugnetState = true;
bool bookState = true;
bool caneofbyrnaState = true;
bool caneofsomariaState = true;
bool capeState = true;
bool mirrorState = true;
bool moonpearlState = true;
bool aghanimState = true;
bool bootsState = true;
bool flippersState = true;
bool halfmagicState = true;
int bowState = 0;
int swordState = 0;
int shieldState = 0;
int tunicState = 0;
int glovesState = 0;
int bottleState = 0;
int boomerangState = 0;
int easternpalaceState = 0;
int desertpalaceState = 0;
int towerofheraState = 0;
int palaceofdarknessState = 0;
int swamppalaceState = 0;
int skullwoodsState = 0;
int thievestownState = 0;
int icepalaceState = 0;
int miserymireState = 0;
int turtlerockState = 0;

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_hookshotOverlayPush_clicked() {
    if (hookshotState) {
        ui->hookshotOverlay->setStyleSheet("background-color: rgba(0,0,0,0%);");
        hookshotState = false;
    } else {
        ui->hookshotOverlay->setStyleSheet("background-color: rgba(0,0,0,60%);");
        hookshotState = true;
    }
}
void MainWindow::on_mushroomOverlayPush_clicked() {
    if (mushroomState) {
        ui->mushroomOverlay->setStyleSheet("background-color: rgba(0,0,0,0%);");
        mushroomState = false;
    } else {
        ui->mushroomOverlay->setStyleSheet("background-color: rgba(0,0,0,60%);");
        mushroomState = true;
    }
}
void MainWindow::on_powderOverlayPush_clicked() {
    if (powderState) {
        ui->powderOverlay->setStyleSheet("background-color: rgba(0,0,0,0%);");
        powderState = false;
    } else {
        ui->powderOverlay->setStyleSheet("background-color: rgba(0,0,0,60%);");
        powderState = true;
    }
}
void MainWindow::on_firerodOverlayPush_clicked() {
    if (firerodState) {
        ui->firerodOverlay->setStyleSheet("background-color: rgba(0,0,0,0%);");
        firerodState = false;
    } else {
        ui->firerodOverlay->setStyleSheet("background-color: rgba(0,0,0,60%);");
        firerodState = true;
    }
}
void MainWindow::on_icerodOverlayPush_clicked() {
    if (icerodState) {
        ui->icerodOverlay->setStyleSheet("background-color: rgba(0,0,0,0%);");
        icerodState = false;
    } else {
        ui->icerodOverlay->setStyleSheet("background-color: rgba(0,0,0,60%);");
        icerodState = true;
    }
}
void MainWindow::on_bombosOverlayPush_clicked() {
    if (bombosState) {
        ui->bombosOverlay->setStyleSheet("background-color: rgba(0,0,0,0%);");
        bombosState = false;
    } else {
        ui->bombosOverlay->setStyleSheet("background-color: rgba(0,0,0,60%);");
        bombosState = true;
    }
}
void MainWindow::on_etherOverlayPush_clicked() {
    if (etherState) {
        ui->etherOverlay->setStyleSheet("background-color: rgba(0,0,0,0%);");
        etherState = false;
    } else {
        ui->etherOverlay->setStyleSheet("background-color: rgba(0,0,0,60%);");
        etherState = true;
    }
}
void MainWindow::on_quakeOverlayPush_clicked() {
    if (quakeState) {
        ui->quakeOverlay->setStyleSheet("background-color: rgba(0,0,0,0%);");
        quakeState = false;
    } else {
        ui->quakeOverlay->setStyleSheet("background-color: rgba(0,0,0,60%);");
        quakeState = true;
    }
}
void MainWindow::on_lampOverlayPush_clicked() {
    if (lampState) {
        ui->lampOverlay->setStyleSheet("background-color: rgba(0,0,0,0%);");
        lampState = false;
    } else {
        ui->lampOverlay->setStyleSheet("background-color: rgba(0,0,0,60%);");
        lampState = true;
    }
}
void MainWindow::on_hammerOverlayPush_clicked() {
    if (hammerState) {
        ui->hammerOverlay->setStyleSheet("background-color: rgba(0,0,0,0%);");
        hammerState = false;
    } else {
        ui->hammerOverlay->setStyleSheet("background-color: rgba(0,0,0,60%);");
        hammerState = true;
    }
}
void MainWindow::on_fluteOverlayPush_clicked() {
    if (fluteState) {
        ui->fluteOverlay->setStyleSheet("background-color: rgba(0,0,0,0%);");
        fluteState = false;
    } else {
        ui->fluteOverlay->setStyleSheet("background-color: rgba(0,0,0,60%);");
        fluteState = true;
    }
}
void MainWindow::on_shovelOverlayPush_clicked() {
    if (shovelState) {
        ui->shovelOverlay->setStyleSheet("background-color: rgba(0,0,0,0%);");
        shovelState = false;
    } else {
        ui->shovelOverlay->setStyleSheet("background-color: rgba(0,0,0,60%);");
        shovelState = true;
    }
}
void MainWindow::on_bugnetOverlayPush_clicked() {
    if (bugnetState) {
        ui->bugnetOverlay->setStyleSheet("background-color: rgba(0,0,0,0%);");
        bugnetState = false;
    } else {
        ui->bugnetOverlay->setStyleSheet("background-color: rgba(0,0,0,60%);");
        bugnetState = true;
    }
}
void MainWindow::on_bookOverlayPush_clicked() {
    if (bookState) {
        ui->bookOverlay->setStyleSheet("background-color: rgba(0,0,0,0%);");
        bookState = false;
    } else {
        ui->bookOverlay->setStyleSheet("background-color: rgba(0,0,0,60%);");
        bookState = true;
    }
}
void MainWindow::on_caneofbyrnaOverlayPush_clicked() {
    if (caneofbyrnaState) {
        ui->caneofbyrnaOverlay->setStyleSheet("background-color: rgba(0,0,0,0%);");
        caneofbyrnaState = false;
    } else {
        ui->caneofbyrnaOverlay->setStyleSheet("background-color: rgba(0,0,0,60%);");
        caneofbyrnaState = true;
    }
}
void MainWindow::on_caneofsomariaOverlayPush_clicked() {
    if (caneofsomariaState) {
        ui->caneofsomariaOverlay->setStyleSheet("background-color: rgba(0,0,0,0%);");
        caneofsomariaState = false;
    } else {
        ui->caneofsomariaOverlay->setStyleSheet("background-color: rgba(0,0,0,60%);");
        caneofsomariaState = true;
    }
}
void MainWindow::on_capeOverlayPush_clicked() {
    if (capeState) {
        ui->capeOverlay->setStyleSheet("background-color: rgba(0,0,0,0%);");
        capeState = false;
    } else {
        ui->capeOverlay->setStyleSheet("background-color: rgba(0,0,0,60%);");
        capeState = true;
    }
}
void MainWindow::on_mirrorOverlayPush_clicked() {
    if (mirrorState) {
        ui->mirrorOverlay->setStyleSheet("background-color: rgba(0,0,0,0%);");
        mirrorState = false;
    } else {
        ui->mirrorOverlay->setStyleSheet("background-color: rgba(0,0,0,60%);");
        mirrorState = true;
    }
}
void MainWindow::on_moonpearlOverlayPush_clicked() {
    if (moonpearlState) {
        ui->moonpearlOverlay->setStyleSheet("background-color: rgba(0,0,0,0%);");
        moonpearlState = false;
    } else {
        ui->moonpearlOverlay->setStyleSheet("background-color: rgba(0,0,0,60%);");
        moonpearlState = true;
    }
}
void MainWindow::on_aghanimOverlayPush_clicked() {
    if (aghanimState) {
        ui->aghanimOverlay->setStyleSheet("background-color: rgba(0,0,0,0%);");
        aghanimState = false;
    } else {
        ui->aghanimOverlay->setStyleSheet("background-color: rgba(0,0,0,60%);");
        aghanimState = true;
    }
}
void MainWindow::on_bootsOverlayPush_clicked() {
    if (bootsState) {
        ui->bootsOverlay->setStyleSheet("background-color: rgba(0,0,0,0%);");
        bootsState = false;
    } else {
        ui->bootsOverlay->setStyleSheet("background-color: rgba(0,0,0,60%);");
        bootsState = true;
    }
}
void MainWindow::on_flippersOverlayPush_clicked() {
    if (flippersState) {
        ui->flippersOverlay->setStyleSheet("background-color: rgba(0,0,0,0%);");
        flippersState = false;
    } else {
        ui->flippersOverlay->setStyleSheet("background-color: rgba(0,0,0,60%);");
        flippersState = true;
    }
}
void MainWindow::on_halfmagicOverlayPush_clicked() {
    if (halfmagicState) {
        ui->halfmagicOverlay->setStyleSheet("background-color: rgba(0,0,0,0%);");
        halfmagicState = false;
    } else {
        ui->halfmagicOverlay->setStyleSheet("background-color: rgba(0,0,0,60%);");
        halfmagicState = true;
    }
}



void MainWindow::on_glovesOverlayPush_clicked() {
    switch(glovesState) {
        case 0:
            ui->glovesOverlay->setStyleSheet("background-color: rgba(0,0,0,0%);");
            glovesState++;
        break;
        case 1:
            ui->glovesImage->setPixmap(QPixmap("images/gloves2.png"));
            glovesState++;
        break;
        case 2:
            ui->glovesImage->setPixmap(QPixmap("images/gloves1.png"));
            ui->glovesOverlay->setStyleSheet("background-color: rgba(0,0,0,60%);");
            glovesState = 0;
        break;
    }
}
void MainWindow::on_tunicOverlayPush_clicked() {
    switch(tunicState) {
        case 0:
            ui->tunicOverlay->setStyleSheet("background-color: rgba(0,0,0,0%);");
            tunicState++;
        break;
        case 1:
            ui->tunicImage->setPixmap(QPixmap("images/tunic2.png"));
            tunicState++;
        break;
        case 2:
            ui->tunicImage->setPixmap(QPixmap("images/tunic3.png"));
            tunicState++;
        break;
        case 3:
            ui->tunicImage->setPixmap(QPixmap("images/tunic1.png"));
            ui->tunicOverlay->setStyleSheet("background-color: rgba(0,0,0,60%);");
            tunicState = 0;
        break;
    }
}
void MainWindow::on_shieldOverlayPush_clicked() {
    switch(shieldState) {
        case 0:
            ui->shieldOverlay->setStyleSheet("background-color: rgba(0,0,0,0%);");
            shieldState++;
        break;
        case 1:
            ui->shieldImage->setPixmap(QPixmap("images/shield2.png"));
            shieldState++;
        break;
        case 2:
            ui->shieldImage->setPixmap(QPixmap("images/shield3.png"));
            shieldState++;
        break;
        case 3:
            ui->shieldImage->setPixmap(QPixmap("images/shield1.png"));
            ui->shieldOverlay->setStyleSheet("background-color: rgba(0,0,0,60%);");
            shieldState = 0;
        break;
    }
}

void MainWindow::on_boomerangOverlayPush_clicked() {
    switch(boomerangState) {
        case 0:
            ui->boomerangOverlay->setStyleSheet("background-color: rgba(0,0,0,0%);");
            boomerangState++;
        break;
        case 1:
            ui->boomerangImage->setPixmap(QPixmap("images/boomerang2.png"));
            boomerangState++;
        break;
        case 2:
            ui->boomerangImage->setPixmap(QPixmap("images/boomerang1.png"));
            ui->boomerangOverlay->setStyleSheet("background-color: rgba(0,0,0,60%);");
            boomerangState = 0;
        break;
    }
}



void MainWindow::on_bottleOverlayPush_clicked() {
    switch(bottleState) {
        case 0:
            ui->bottleOverlay->setStyleSheet("background-color: rgba(0,0,0,0%);");
            bottleState++;
        break;
        case 1:
            ui->bottleImage->setPixmap(QPixmap("images/bottle2.png"));
            bottleState++;
        break;
        case 2:
            ui->bottleImage->setPixmap(QPixmap("images/bottle3.png"));
            bottleState++;
        break;
        case 3:
            ui->bottleImage->setPixmap(QPixmap("images/bottle4.png"));
            bottleState++;
        break;
        case 4:
            ui->bottleImage->setPixmap(QPixmap("images/bottle1.png"));
            ui->bottleOverlay->setStyleSheet("background-color: rgba(0,0,0,60%);");
            bottleState = 0;
        break;
    }
}


void MainWindow::on_swordOverlayPush_clicked() {
    switch(swordState) {
        case 0:
            ui->swordOverlay->setStyleSheet("background-color: rgba(0,0,0,0%);");
            swordState++;
        break;
        case 1:
            ui->swordImage->setPixmap(QPixmap("images/sword2.png"));
            swordState++;
        break;
        case 2:
            ui->swordImage->setPixmap(QPixmap("images/sword3.png"));
            swordState++;
        break;
        case 3:
            ui->swordImage->setPixmap(QPixmap("images/sword4.png"));
            swordState++;
        break;
        case 4:
            ui->swordImage->setPixmap(QPixmap("images/sword1.png"));
            ui->swordOverlay->setStyleSheet("background-color: rgba(0,0,0,60%);");
            swordState = 0;
        break;
    }
}

void MainWindow::on_bowOverlayPush_clicked() {
    switch(bowState) {
        case 0:
            ui->bowOverlay->setStyleSheet("background-color: rgba(0,0,0,0%);");
            bowState++;
        break;
        case 1:
            ui->bowImage->setPixmap(QPixmap("images/arrow1.png"));
            bowState++;
        break;
        case 2:
            ui->bowImage->setPixmap(QPixmap("images/bow2.png"));
            bowState++;
        break;
        case 3:
            ui->bowImage->setPixmap(QPixmap("images/bow3.png"));
            bowState++;
        break;
        case 4:
            ui->bowImage->setPixmap(QPixmap("images/bow1.png"));
            ui->bowOverlay->setStyleSheet("background-color: rgba(0,0,0,60%);");
            bowState = 0;
        break;
    }
}

void MainWindow::on_easternpalaceOverlayPush_clicked() {
    switch(easternpalaceState) {
        case 0:
            ui->easternpalaceOverlay->setStyleSheet("background-color: rgba(0,0,0,0%);");
            easternpalaceState++;
        break;
        case 1:
            ui->easternpalaceRewardImage->setPixmap(QPixmap("images/crystal2.png"));
            easternpalaceState++;
        break;
        case 2:
            ui->easternpalaceRewardImage->setPixmap(QPixmap("images/pendant1.png"));
            easternpalaceState++;
        break;
        case 3:
            ui->easternpalaceRewardImage->setPixmap(QPixmap("images/pendant2.png"));
            easternpalaceState++;
        break;
        case 4:
            ui->easternpalaceRewardImage->setPixmap(QPixmap("images/crystal1.png"));
            ui->easternpalaceOverlay->setStyleSheet("background-color: rgba(0,0,0,60%);");
            easternpalaceState = 0;
        break;
    }
}

void MainWindow::on_desertpalaceOverlayPush_clicked() {
    switch(desertpalaceState) {
        case 0:
            ui->desertpalaceOverlay->setStyleSheet("background-color: rgba(0,0,0,0%);");
            desertpalaceState++;
        break;
        case 1:
            ui->desertpalaceRewardImage->setPixmap(QPixmap("images/crystal2.png"));
            desertpalaceState++;
        break;
        case 2:
            ui->desertpalaceRewardImage->setPixmap(QPixmap("images/pendant1.png"));
            desertpalaceState++;
        break;
        case 3:
            ui->desertpalaceRewardImage->setPixmap(QPixmap("images/pendant2.png"));
            desertpalaceState++;
        break;
        case 4:
            ui->desertpalaceRewardImage->setPixmap(QPixmap("images/crystal1.png"));
            ui->desertpalaceOverlay->setStyleSheet("background-color: rgba(0,0,0,60%);");
            desertpalaceState = 0;
        break;
    }
}
void MainWindow::on_towerofheraOverlayPush_clicked() {
    switch(towerofheraState) {
        case 0:
            ui->towerofheraOverlay->setStyleSheet("background-color: rgba(0,0,0,0%);");
            towerofheraState++;
        break;
        case 1:
            ui->towerofheraRewardImage->setPixmap(QPixmap("images/crystal2.png"));
            towerofheraState++;
        break;
        case 2:
            ui->towerofheraRewardImage->setPixmap(QPixmap("images/pendant1.png"));
            towerofheraState++;
        break;
        case 3:
            ui->towerofheraRewardImage->setPixmap(QPixmap("images/pendant2.png"));
            towerofheraState++;
        break;
        case 4:
            ui->towerofheraRewardImage->setPixmap(QPixmap("images/crystal1.png"));
            ui->towerofheraOverlay->setStyleSheet("background-color: rgba(0,0,0,60%);");
            towerofheraState = 0;
        break;
    }
}

void MainWindow::on_palaceofdarknessOverlayPush_clicked() {
    switch(palaceofdarknessState) {
        case 0:
            ui->palaceofdarknessOverlay->setStyleSheet("background-color: rgba(0,0,0,0%);");
            palaceofdarknessState++;
        break;
        case 1:
            ui->palaceofdarknessRewardImage->setPixmap(QPixmap("images/crystal2.png"));
            palaceofdarknessState++;
        break;
        case 2:
            ui->palaceofdarknessRewardImage->setPixmap(QPixmap("images/pendant1.png"));
            palaceofdarknessState++;
        break;
        case 3:
            ui->palaceofdarknessRewardImage->setPixmap(QPixmap("images/pendant2.png"));
            palaceofdarknessState++;
        break;
        case 4:
            ui->palaceofdarknessRewardImage->setPixmap(QPixmap("images/crystal1.png"));
            ui->palaceofdarknessOverlay->setStyleSheet("background-color: rgba(0,0,0,60%);");
            palaceofdarknessState = 0;
        break;
    }
}

void MainWindow::on_swamppalaceOverlayPush_clicked() {
    switch(swamppalaceState) {
        case 0:
            ui->swamppalaceOverlay->setStyleSheet("background-color: rgba(0,0,0,0%);");
            swamppalaceState++;
        break;
        case 1:
            ui->swamppalaceRewardImage->setPixmap(QPixmap("images/crystal2.png"));
            swamppalaceState++;
        break;
        case 2:
            ui->swamppalaceRewardImage->setPixmap(QPixmap("images/pendant1.png"));
            swamppalaceState++;
        break;
        case 3:
            ui->swamppalaceRewardImage->setPixmap(QPixmap("images/pendant2.png"));
            swamppalaceState++;
        break;
        case 4:
            ui->swamppalaceRewardImage->setPixmap(QPixmap("images/crystal1.png"));
            ui->swamppalaceOverlay->setStyleSheet("background-color: rgba(0,0,0,60%);");
            swamppalaceState = 0;
        break;
    }
}
void MainWindow::on_skullwoodsOverlayPush_clicked() {
    switch(skullwoodsState) {
        case 0:
            ui->skullwoodsOverlay->setStyleSheet("background-color: rgba(0,0,0,0%);");
            skullwoodsState++;
        break;
        case 1:
            ui->skullwoodsRewardImage->setPixmap(QPixmap("images/crystal2.png"));
            skullwoodsState++;
        break;
        case 2:
            ui->skullwoodsRewardImage->setPixmap(QPixmap("images/pendant1.png"));
            skullwoodsState++;
        break;
        case 3:
            ui->skullwoodsRewardImage->setPixmap(QPixmap("images/pendant2.png"));
            skullwoodsState++;
        break;
        case 4:
            ui->skullwoodsRewardImage->setPixmap(QPixmap("images/crystal1.png"));
            ui->skullwoodsOverlay->setStyleSheet("background-color: rgba(0,0,0,60%);");
            skullwoodsState = 0;
        break;
    }
}

void MainWindow::on_thievestownOverlayPush_clicked() {
    switch(thievestownState) {
        case 0:
            ui->thievestownOverlay->setStyleSheet("background-color: rgba(0,0,0,0%);");
            thievestownState++;
        break;
        case 1:
            ui->thievestownRewardImage->setPixmap(QPixmap("images/crystal2.png"));
            thievestownState++;
        break;
        case 2:
            ui->thievestownRewardImage->setPixmap(QPixmap("images/pendant1.png"));
            thievestownState++;
        break;
        case 3:
            ui->thievestownRewardImage->setPixmap(QPixmap("images/pendant2.png"));
            thievestownState++;
        break;
        case 4:
            ui->thievestownRewardImage->setPixmap(QPixmap("images/crystal1.png"));
            ui->thievestownOverlay->setStyleSheet("background-color: rgba(0,0,0,60%);");
            thievestownState = 0;
        break;
    }
}

void MainWindow::on_icepalaceOverlayPush_clicked() {
    switch(icepalaceState) {
        case 0:
            ui->icepalaceOverlay->setStyleSheet("background-color: rgba(0,0,0,0%);");
            icepalaceState++;
        break;
        case 1:
            ui->icepalaceRewardImage->setPixmap(QPixmap("images/crystal2.png"));
            icepalaceState++;
        break;
        case 2:
            ui->icepalaceRewardImage->setPixmap(QPixmap("images/pendant1.png"));
            icepalaceState++;
        break;
        case 3:
            ui->icepalaceRewardImage->setPixmap(QPixmap("images/pendant2.png"));
            icepalaceState++;
        break;
        case 4:
            ui->icepalaceRewardImage->setPixmap(QPixmap("images/crystal1.png"));
            ui->icepalaceOverlay->setStyleSheet("background-color: rgba(0,0,0,60%);");
            icepalaceState = 0;
        break;
    }
}
void MainWindow::on_miserymireOverlayPush_clicked() {
    switch(miserymireState) {
        case 0:
            ui->miserymireOverlay->setStyleSheet("background-color: rgba(0,0,0,0%);");
            miserymireState++;
        break;
        case 1:
            ui->miserymireRewardImage->setPixmap(QPixmap("images/crystal2.png"));
            miserymireState++;
        break;
        case 2:
            ui->miserymireRewardImage->setPixmap(QPixmap("images/pendant1.png"));
            miserymireState++;
        break;
        case 3:
            ui->miserymireRewardImage->setPixmap(QPixmap("images/pendant2.png"));
            miserymireState++;
        break;
        case 4:
            ui->miserymireRewardImage->setPixmap(QPixmap("images/crystal1.png"));
            ui->miserymireOverlay->setStyleSheet("background-color: rgba(0,0,0,60%);");
            miserymireState = 0;
        break;
    }
}

void MainWindow::on_turtlerockOverlayPush_clicked() {
    switch(turtlerockState) {
        case 0:
            ui->turtlerockOverlay->setStyleSheet("background-color: rgba(0,0,0,0%);");
            turtlerockState++;
        break;
        case 1:
            ui->turtlerockRewardImage->setPixmap(QPixmap("images/crystal2.png"));
            turtlerockState++;
        break;
        case 2:
            ui->turtlerockRewardImage->setPixmap(QPixmap("images/pendant1.png"));
            turtlerockState++;
        break;
        case 3:
            ui->turtlerockRewardImage->setPixmap(QPixmap("images/pendant2.png"));
            turtlerockState++;
        break;
        case 4:
            ui->turtlerockRewardImage->setPixmap(QPixmap("images/crystal1.png"));
            ui->turtlerockOverlay->setStyleSheet("background-color: rgba(0,0,0,60%);");
            turtlerockState = 0;
        break;
    }
}

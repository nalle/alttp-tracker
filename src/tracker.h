#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QAbstractButton>

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_bowOverlayPush_clicked();
    void on_swordOverlayPush_clicked();
    void on_shieldOverlayPush_clicked();
    void on_tunicOverlayPush_clicked();
    void on_boomerangOverlayPush_clicked();
    void on_hookshotOverlayPush_clicked();
    void on_mushroomOverlayPush_clicked();
    void on_powderOverlayPush_clicked();
    void on_firerodOverlayPush_clicked();
    void on_icerodOverlayPush_clicked();
    void on_bombosOverlayPush_clicked();
    void on_etherOverlayPush_clicked();
    void on_quakeOverlayPush_clicked();
    void on_lampOverlayPush_clicked();
    void on_hammerOverlayPush_clicked();
    void on_fluteOverlayPush_clicked();
    void on_shovelOverlayPush_clicked();
    void on_bugnetOverlayPush_clicked();
    void on_bookOverlayPush_clicked();
    void on_bottleOverlayPush_clicked();
    void on_caneofbyrnaOverlayPush_clicked();
    void on_caneofsomariaOverlayPush_clicked();
    void on_capeOverlayPush_clicked();
    void on_mirrorOverlayPush_clicked();
    void on_moonpearlOverlayPush_clicked();
    void on_aghanimOverlayPush_clicked();
    void on_bootsOverlayPush_clicked();
    void on_glovesOverlayPush_clicked();
    void on_flippersOverlayPush_clicked();
    void on_halfmagicOverlayPush_clicked();
    void on_easternpalaceOverlayPush_RightClicked();
    void on_desertpalaceOverlayPush_RightClicked();
    void on_towerofheraOverlayPush_RightClicked();
    void on_palaceofdarknessOverlayPush_RightClicked();
    void on_swamppalaceOverlayPush_RightClicked();
    void on_skullwoodsOverlayPush_RightClicked();
    void on_thievestownOverlayPush_RightClicked();
    void on_icepalaceOverlayPush_RightClicked();
    void on_miserymireOverlayPush_RightClicked();
    void on_turtlerockOverlayPush_RightClicked();
    void on_easternpalaceOverlayPush_clicked();
    void on_desertpalaceOverlayPush_clicked();
    void on_towerofheraOverlayPush_clicked();
    void on_palaceofdarknessOverlayPush_clicked();
    void on_swamppalaceOverlayPush_clicked();
    void on_skullwoodsOverlayPush_clicked();
    void on_thievestownOverlayPush_clicked();
    void on_icepalaceOverlayPush_clicked();
    void on_miserymireOverlayPush_clicked();
    void on_turtlerockOverlayPush_clicked();
    void on_bombosOverlayPush_RightClicked(); 
    void on_etherOverlayPush_RightClicked(); 
    void on_quakeOverlayPush_RightClicked(); 

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H

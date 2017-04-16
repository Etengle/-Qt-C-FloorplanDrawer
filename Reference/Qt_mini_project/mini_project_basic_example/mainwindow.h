#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QApplication>
#include <QMouseEvent>
#include <role.h>
#include <obstacle.h>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);

protected:
    void paintEvent(QPaintEvent *);    //繪製背景圖
    void mousePressEvent(QMouseEvent *event);	//滑鼠點下事件
    void keyPressEvent(QKeyEvent *event);	//鍵盤事件

private slots:
    void birdAction();			//鳥的動作
    void pipeAction();			//綠色管子的動作
    void collisDete();			//碰撞偵測
private:

    void birdup();              // 設定鳥飛行速度參數
    void createPipe();			// 產生水管
    void createBird();          // 產生角色 - 鳥
    void gameLose();			 //遊戲結束
    void gameStart();			 //遊戲開始
    void gameRedy();             //遊戲預備

    ROLE *birds;			// 建立一隻角色 - 鳥
    double birdV;			// 鳥的速度
    QTimer *birdTimer;
    double timedata;			// birdTimer interval
    double birdV_array[15];
    double index_birdV;
    enum{lose=0,start=1,redy=2};  // Enum三個參數, 代表遊戲狀態
    int gamemod;		//目前遊戲狀態, 0=lose, 1=start, 2=redy
    // 遊戲狀態預設流程： redy -> start -> lose -> redy -> start .... 不斷循環
    enum{pipeCount=5};		//  pipe 數量
    OBSTACLE *pipe[pipeCount];	// 建立水管
    QTimer *pipeTimer;
    int pipeTValue;     // pipeTimer interval
    int pipeXgap;		// 管子間距
    int lastPipe;		// the flag of rightest pipe

    int win_width;      // 視窗寬度
    int win_height;     // 視窗高度
};

#endif // MAINWINDOW_H

#include "mainwindow.h"
#include <QPainter>
#include <string>
#include <fstream>
#include <iostream>
using namespace std;

typedef struct _REC_{
    int x, y;   // x, y
    int w, h;   // width, height
    int r;      // rotation
    int id;
} Rec;

Rec *rec;
int n; // #sub-blocks
double boundarySize;

void My_Init();

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    // The constructor of MainWindow
    win_width = 500;
    win_height = 500;
    this->setFixedSize(win_width, win_height);	//視窗大小
    My_Init();
}

MainWindow::~MainWindow()
{
    // The destructor of MainWindow
}

// 讀檔
void My_Init(){
    ifstream fin;
    int x, y, w, h, r, id;
    fin.open("/Users/Slighten/result.rpt", ios::in);
    if (!fin) { cerr << "read fail\n"; exit(0); }
    fin >> n >> boundarySize;
    rec = new Rec[n];
    for (int i = 0; i < n; i++){
        fin >> id >> x >> y >> w >> h >> r;
        rec[i].x = x;
        rec[i].y = y;
        rec[i].id = id;
        rec[i].r = r;
        if (r){
            rec[i].w = h;
            rec[i].h = w;
        }
        else {
            rec[i].w = w;
            rec[i].h = h;
        }
    }
    fin.close();
}

// 繪圖事件, 用来產生背景
// 會自動一直 call 他
void MainWindow::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    // this 代表 Main Window
    // 代表這個 painter 是要畫在 Main Window 上
    // 若要畫在一張圖上
    // 也可以自己創 QImage image; QPainter painter(&image);
    // 畫完後 image.save(路徑, 圖檔類型);

    // 筆是畫方塊外框，筆刷是畫方塊裡面
    painter.setPen(QPen(Qt::black, 1.2, Qt::SolidLine)); // 設定筆：黑色、1.2px、實線
    painter.setBrush(QBrush(Qt::blue, Qt::BDiagPattern)); // 設定筆刷：藍色、斜線陰影
    // 畫每個方塊
    for (int i = 0; i < n; i++){
        // 畫矩形
        painter.drawRect(rec[i].x,rec[i].y,rec[i].w,rec[i].h);
        // 畫方塊上的斜線（block 方向）
        if (!rec[i].r)
            painter.drawLine(rec[i].x,rec[i].y+rec[i].h-10,
                             rec[i].x+10, rec[i].y+rec[i].h);
        else
            painter.drawLine(rec[i].x,rec[i].y+10,
                             rec[i].x+10, rec[i].y);
        // 畫字 (id)
        painter.drawText(rec[i].x+0.38*rec[i].w,rec[i].y+0.62*rec[i].h,
                         QString::number(rec[i].id));
    }
    painter.setPen(QPen(Qt::red, 2, Qt::DashLine)); // 設定筆：紅色、2px、虛線
    painter.setBrush(Qt::NoBrush); // 設定筆刷：無筆刷
    // 畫邊界
    painter.drawRect(0,0,boundarySize,boundarySize);
    painter.end();
}

//main.cpp
#include <iostream>
#include <string>
#include "Train.h"
using namespace std;
Train Go{};

void JudgeFrontorBack() {//判斷前與後
    for (int i = 0; i < 7; i++) { //里程前、後
        if ((Go.flag) && (Go.name[i] == Go.start)) {//前 起點
            Go.Front = Go.name[i];
            Go.Frontnum = i;
            Go.Frontstart = true;
            Go.flag = false;
        }
        if ((Go.flag) && (Go.name[i] == Go.end)) {//前 終點
            Go.Front = Go.name[i];
            Go.Frontnum = i;
            Go.Frontstart = false;
            Go.flag = false;
        }
        if ((!Go.flag) && ((Go.name[i] == Go.start) || (Go.name[i] == Go.end))) {//後
            Go.Backnum = i;
            Go.Back = Go.name[i];
        }
    }
}

void Turn() {//順逆時鐘
    //後到前(順時鐘) ex CK-->BK-->AK
    Go.distance[0] = Go.station[Go.Backnum] - Go.station[Go.Frontnum];
    //前到後(逆時鐘) ex AK-->GK-->FK
    if (Go.Frontnum == 0) {//剛好為第一個
        Go.Frontnum = 7;//移到最後面
        Go.distance[1] = Go.station[Go.Frontnum] - Go.station[Go.Backnum];
    } else { //不是
        Go.distance[1] = Go.station[7] - Go.station[Go.Backnum];//後面距離
        Go.distance[1] += Go.station[Go.Frontnum];//前面距離
    }
}

void Output() {//輸出
    //輸出
    cout << Go.start << "站到" << Go.end << "站\n";
    //判斷距離
    cout << "要搭乘往";
    if (Go.distance[0] < Go.distance[1]) {//後到前<前到後
        if (Go.Frontstart) {
            if (Go.Backnum <= 1) {//會超出界線
                cout << Go.name[Go.Backnum+7-2];
            } else {
                cout << Go.name[Go.Backnum-2];
            }
            cout << ".";
            cout << Go.name[Go.Backnum-1];
            cout << "方向的列車\n";   
            cout << "搭乘距離為" << Go.distance[0] << "km\n"; 
        } else {
            cout << Go.name[Go.Backnum-1] << ".";
            if (Go.Backnum <= 1) {//會超出界線
                cout << Go.name[Go.Backnum+7-2];
            } else {
                cout << Go.name[Go.Backnum-2];
            }
            cout << "方向的列車\n";   
            cout << "搭乘距離為" << Go.distance[0] << "km\n";
        }
    } else {//後到前>*前到後*
        if (Go.Frontstart) {
            cout << Go.name[Go.Frontnum-1] << ".";
            if (Go.Frontnum <= 1) {//會超出界線
                cout << Go.name[Go.Frontnum+7-2];
            } else {
                cout << Go.name[Go.Frontnum-2];
            }
            cout << "方向的列車\n";   
            cout << "搭乘距離為" << Go.distance[1] << "km\n";
        } else {
            if (Go.Frontnum <= 1) {//會超出界線
                cout << Go.name[Go.Frontnum+7-2];
            } else {
                cout << Go.name[Go.Frontnum-2];
            }
            cout << ".";
            cout << Go.name[Go.Frontnum-1];
            cout << "方向的列車\n";   
            cout << "搭乘距離為" << Go.distance[1] << "km\n"; 
        }
    }
}

int main() {
    cout << "請輸入起點站：";
    cin >> Go.start;
    cout << "請輸入終點站：";
    cin >> Go.end;

    JudgeFrontorBack();//判斷前與後
    Turn();//順逆時鐘
    Output();//輸出
}

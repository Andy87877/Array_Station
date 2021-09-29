#include <iostream>
#include <string>
using namespace std;

int main() {
    float station[8] = {0,2,4,5.3,6.9,8.7,10.2,14.7};//里程
    string name[7] = {"AK","BK","CK","DK","EK","FK","GK"};//對應車站
    float distance[2] = {0,0};//順逆時鐘的里程數

    string start, end;//起點終點
    cout << "請輸入起點站：";
    cin >> start;
    cout << "請輸入終點站：";
    cin >> end;

    string Front, Back;//里程靠前、後  方便計算順逆時鐘
    int Frontnum, Backnum;//位置
    bool flag = true; //是否里程是前面 
    bool Frontstart = false; //前面是不是起點 方便後面的輸出

    for (int i = 0; i < 7; i++) { //里程前、後
        if ((flag) && (name[i] == start)) {//前 起點
            Front = name[i];
            Frontnum = i;
            Frontstart = true;
            flag = false;
        }
        if ((flag) && (name[i] == end)) {//前 終點
            Front = name[i];
            Frontnum = i;
            Frontstart = false;
            flag = false;
        }
        if ((!flag) && ((name[i] == start) || (name[i] == end))) {//後
            Backnum = i;
            Back = name[i];
        }
    }


    //後到前(順時鐘) ex CK-->BK-->AK
    distance[0] = station[Backnum] - station[Frontnum];
    //前到後(逆時鐘) ex AK-->GK-->FK
    if (Frontnum == 0) {//剛好為第一個
        Frontnum = 7;//移到最後面
        distance[1] = station[Frontnum] - station[Backnum];
    } else { //不是
        distance[1] = station[7] - station[Backnum];//後面距離
        distance[1] += station[Frontnum];//前面距離
    }
    

    //輸出
    cout << start << "站到" << end << "站\n";
    //判斷距離
    cout << "要搭乘往";
    if (distance[0] < distance[1]) {//後到前<前到後
        if (Frontstart) {
            if (Backnum <= 1) {//會超出界線
                cout << name[Backnum+7-2];
            } else {
                cout << name[Backnum-2];
            }
            cout << ".";
            cout << name[Backnum-1];
            cout << "方向的列車\n";   
            cout << "搭乘距離為" << distance[0] << "km\n"; 
        } else {
            cout << name[Backnum-1] << ".";
            if (Backnum <= 1) {//會超出界線
                cout << name[Backnum+7-2];
            } else {
                cout << name[Backnum-2];
            }
            cout << "方向的列車\n";   
            cout << "搭乘距離為" << distance[0] << "km\n";
        }
    } else {//後到前>*前到後*
        if (Frontstart) {
            cout << name[Frontnum-1] << ".";
            if (Frontnum <= 1) {//會超出界線
                cout << name[Frontnum+7-2];
            } else {
                cout << name[Frontnum-2];
            }
            cout << "方向的列車\n";   
            cout << "搭乘距離為" << distance[1] << "km\n";
        } else {
            if (Frontnum <= 1) {//會超出界線
                cout << name[Frontnum+7-2];
            } else {
                cout << name[Frontnum-2];
            }
            cout << ".";
            cout << name[Frontnum-1];
            cout << "方向的列車\n";   
            cout << "搭乘距離為" << distance[1] << "km\n"; 
        }
    }
}

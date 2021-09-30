//Train.h
#include <iostream>
#include <string>
using namespace std;

class Train {
    public:
        float station[8] = {0,2,4,5.3,6.9,8.7,10.2,14.7};//里程
        string name[7] = {"AK","BK","CK","DK","EK","FK","GK"};//對應車站
        float distance[2] = {0,0};//順逆時鐘的里程數

        string start, end;//起點終點
        string Front, Back;//里程靠前、後  方便計算順逆時鐘
        
        int Frontnum, Backnum;//位置
        bool flag = true; //是否里程是前面 
        bool Frontstart = false; //前面是不是起點 方便後面的輸出
};

//7-22 龟兔赛跑 （20 分）

//乌龟与兔子进行赛跑，跑场是一个矩型跑道，跑道边可以随地进行休息。乌龟每分钟可以前进3米，兔子每分钟前进9米；兔子嫌乌龟跑得慢，觉得肯定能跑赢乌龟，于是，每跑10分钟回头看一下乌龟，若发现自己超过乌龟，就在路边休息，每次休息30分钟，否则继续跑10分钟；而乌龟非常努力，一直跑，不休息。假定乌龟与兔子在同一起点同一时刻开始起跑，请问T分钟后乌龟和兔子谁跑得快？
#include<iostream>
using namespace std;
int main()
{
    int times,intTime,restTime,t=0,r=0,count=0;
    cin >> times;
    intTime = times-(times%10);
    restTime = times%10;
    for(int i=0; i<intTime; i+=10) {
        t+=30;
        if(count) {
            --count;
            continue;
        }
        else {
            r+=90;
            if(r>t) {
                count=3;
            }
        }
    }
    if(!count) r+=9*restTime;
    t+=3*restTime;
    if(r>t) {
        cout<<"^_^ "<<r<<endl;
    }
    else if(r<t) {
        cout<<"@_@ "<<t<<endl;
    }
    else {
        cout<<"-_- "<<t<<endl;
    }
    return 0;
}

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

#include<iostream>
#include<cstdio>
using namespace std;
void move(char getone, char putone)
{
    printf("%c -> %c\n",getone,putone);
}
void hanoi(int n, char one,char two,char three)
{
    if(n==1)
        move(one,three);
    else
    {
        hanoi(n-1,one,three,two);
        move(one,three);
        hanoi(n-1,two,one,three);
    }
}
int main()
{
    int n;
    while(cin>>n)
    {
        hanoi(n,'a','b','c');
    }
    return 0;
}

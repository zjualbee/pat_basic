#include<iostream>
#include<iomanip>
using namespace std;
int main()
{
    double a;
    while((cin>>a)!=NULL)
    {
        double s=0;
        if(a<=15)
            s=a*4/3;
        else
            s=2.5*a-17.5;
        cout<<fixed;
        cout<<setprecision(2)<<s<<endl;
    }
    return 0;
}

#include<iostream>
#include<stack>
using namespace std;

int main()
{
    stack<int> s1,s2;
    int v1,v2;
    cin>>v1>>v2;
    if(v1>v2)
    {
        v1 ^= v2;
        v2 ^= v1;
        v1 ^= v2;
    }
    int num;
    char op;
    while(true)
    {
        cin>>op;
        if(op=='A')
        {
            cin>>num;
            if(s1.size()==v1)
            {
                if(s2.size()==0)
                {
                    while(s1.size())
                    {
                        s2.push(s1.top());
                        s1.pop();
                    }
                    s1.push(num);
                }
                else{
                    cout<<"ERROR:Full"<<endl;
                    continue;
                }
            }
            else
                s1.push(num);
        }
        else if(op=='D')
        {
            if(s2.size()==0)
            {
                if(s1.size()==0){
                    cout<<"ERROR:Empty"<<endl;
                    continue;
                }
                else{
                    while(s1.size())
                    {
                        s2.push(s1.top());
                        s1.pop();
                    }
                }
            }
            cout<<s2.top()<<endl;
            s2.pop();
        }
        else if(op=='T')
            exit(0);
    }
    return 0;
    
}

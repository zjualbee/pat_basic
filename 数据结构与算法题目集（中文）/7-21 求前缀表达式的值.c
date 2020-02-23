#include<iostream>
#include<stack>
#include<string>
using namespace std;
int main()
{
    string s;
    getline(cin,s,'\n');
    int len=s.length();
    double a,b,res;
    stack<double> st;
    double num;
    int i,multiple;
    for(i=len-1;i>=0;i--)
    {
        if(s[i]-'0'>=0 && s[i]-'0'<=9)
        {
            num=s[i]-'0';
            multiple=10;
            for(i--;i>=0;i--)
            {
                if((s[i]-'0'>=0 && s[i]-'0'<=9) || s[i]=='.')
                {
                    if(s[i]-'0'>=0 && s[i]-'0'<=9)
                    {
                        num+=multiple*(s[i]-'0');
                        multiple*=10;
                    }
                    else{
                        num/=multiple;
                        multiple=1;
                    }
                }
                
                else if(s[i]=='-')
                {
                    num*=-1;
                }
                else
                    break;
            }
            st.push(num);
        }
        else if(s[i]==' ')
            continue;
        else
        {
            a=st.top();
            st.pop();
            b=st.top();
            st.pop();
            if(s[i]=='+')
                res=a+b;
            else if(s[i]=='-')
                res=a-b;
            else if(s[i]=='*')
                res=a*b;
            else if(s[i]=='/')
            {
                if(b==0){
                    printf("ERROR\n");
                    return 0;
                }
                else
                    res=a/b;
            }
            st.push(res);
        }
    }
    printf("%.1f\n",st.top());
    return 0;
}

//1018. 锤子剪刀布 (20)
#include<iostream>
using namespace std;
int wina[3],winb[3],result[3];
void f(char a,char b)
{
	if(a==b)
	{
		result[1]++;
	}

	else 
	{
		if(a=='C')
		{
			switch(b)
			{					
			case'B':
				{
					result[2]++;
					winb[2]++;
					break;
				}
			case'J':
				{
					result[0]++;
					wina[0]++;
					break;
				}
			}
		}
		else if(a=='B')
		{
			switch(b)
			{
			case'C':
				{
					result[0]++;
					wina[2]++;
					break;
				}
			case'J':
				{
					result[2]++;
					winb[1]++;
					break;
				}
			}
		}
		else if(a=='J')
		{
			switch(b)
			{
			case'C':
				{
					result[2]++;
					winb[0]++;
					break;
				}
			case'B':
				{
					result[0]++;
					wina[1]++;
					break;
				}
			}
		}
	}
}
int max(int win[3])
{
	if((win[2]>=win[1]) && (win[2]>=win[0])) return 2;
    if((win[0]>=win[1]) && (win[0]>=win[2])) return 0;
    if((win[1]>=win[0]) && (win[1]>=win[1])) return 1;
}
int main()
{
	int n;
	while((cin>>n)!=NULL)
	{
        if(n<=100000&&n>0)
        {
            char temp[3];
            getchar();
            for(int i=0;i<n;i++)
            {
                gets(temp);
				f(temp[0],temp[2]);
			}	
			cout<<result[0]<<" "<<result[1]<<" "<<result[2]<<endl;
			cout<<result[2]<<" "<<result[1]<<" "<<result[0]<<endl;

			char index[3]={'C','J','B'};
			cout<<index[max(wina)]<<" "<<index[max(winb)]<<endl;
		}
	}
	return 0;
}
/*
#include <iostream>
using namespace std;
//result[0]表示A赢B的次数；result[1]表示A与B战平的次数；result[2]表示A败给B的次数
//winA[0]表示A以‘C’战胜B的次数，winA[1]表示A以‘J’战胜B的次数，winA[2]表示A以‘B’战胜B的次数，对B同理
int result[3],winA[3],winB[3];
void f(char player_A,char player_B)
{
    if(player_A == player_B)//战平
    {
        result[1]++;
    }
    else
    {
        switch(player_A)
        {
            case 'C':
                if(player_B=='B')//B以‘B’战胜A
                {
                    result[2]++;
                    winB[2]++;
                }
                else//A以‘C’胜B
                {
                    result[0]++;
                    winA[0]++;
                }
                break;
            case 'J':
                if(player_B=='C')//B以‘C’胜A
                {
                    result[2]++;
                    winB[0]++;
                }
                else//A以‘J’胜B
                {
                    result[0]++;
                    winA[1]++;
                }
                break;
            case 'B':
                if(player_B=='J')//B以‘J’胜A
                {
                    result[2]++;
                    winB[1]++;
                }
                else//A以‘B’胜B
                {
                    result[0]++;
                    winA[2]++;
                }
        }
    }
}
int max(int win[3])//求得数组中存储最大数的序号
{
    if((win[2]>=win[1]) && (win[2]>=win[0])) return 2;
    if((win[0]>=win[1]) && (win[0]>=win[2])) return 0;
    if((win[1]>=win[0]) && (win[1]>=win[1])) return 1;
}
int main()
{
    int N;
    cin>>N;
    char player_A,player_B;
    while(N--)
    {
        cin>>player_A>>player_B;
        f(player_A,player_B);
    }
    cout<<result[0]<<" "<<result[1]<<" "<<result[2]<<endl;
    cout<<result[2]<<" "<<result[1]<<" "<<result[0]<<endl;
    char index2char[3] = {'C','J','B'};//0代表‘C’即‘锤’、1代表‘J’即‘剪’、2代表‘B’即‘布’
    cout<<index2char[max(winA)]<<" "<<index2char[max(winB)];
    return 0;
}

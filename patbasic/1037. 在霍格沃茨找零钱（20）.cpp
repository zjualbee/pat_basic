//1037. 在霍格沃茨找零钱（20）
#include<iostream>
using namespace std;
struct money
{
	long int galleon;
	int sickle;
	int knut;
};
int main()
{
	money origin,real;
	char op;
	while((cin>>origin.galleon>>op>>origin.sickle>>op>>origin.knut>>real.galleon>>op>>real.sickle>>op>>real.knut)!=NULL)
	{
		money final;
		int flag=1;
		if(real.galleon*17*29+real.sickle*29+real.knut<origin.galleon*17*29+origin.sickle*29+origin.knut)
		{
			final = real;
			real = origin;
			origin = final;
			flag=-1;
		}
		
		if(real.knut>=origin.knut)
			final.knut=real.knut-origin.knut;
		else
		{
			final.knut=real.knut+29-origin.knut;
			real.sickle-=1;
		}
		if(real.sickle>=origin.sickle)
			final.sickle=real.sickle-origin.sickle;
		else
		{
			final.sickle=real.sickle-origin.sickle+17;
			real.galleon-=1;
		}
		final.galleon=real.galleon-origin.galleon;
		cout<<flag*final.galleon<<"."<<final.sickle<<"."<<final.knut<<endl;
	}
	return 0;
}
//00-вт╡Б5. Shuffling Machine (20)
#include<iostream>
using namespace std;
char *card[54]={"S1","S2","S3","S4","S5","S6","S7","S8","S9","S10","S11","S12","S13",
                "H1","H2","H3","H4","H5","H6","H7","H8","H9","H10","H11","H12","H13",
                "C1","C2","C3","C4","C5","C6","C7","C8","C9","C10","C11","C12","C13",
                "D1","D2","D3","D4","D5","D6","D7","D8","D9","D10","D11","D12","D13","J1","J2"};
int main()
{
	int n;
	cin>>n;
	int shuffle[54];
	for(int i=0;i<54;i++)
		cin>>shuffle[i];
	char *temp[54],*result[54];
	for(int j=0;j<n;j++)
	{
		for(int i=0;i<54;i++)
			result[shuffle[i]-1]=card[i];
		for(int i=0;i<54;i++)
			card[i]=result[i];
	}
	cout<<card[0];
	for(int i=1;i<54;i++)
		cout<<" "<<card[i];
	return 0;
}
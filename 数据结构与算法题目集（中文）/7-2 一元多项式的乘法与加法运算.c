#include<iostream>
#include<map>
using namespace std;
int main()
{
    int num1, num2, xi,zhi,t;
    map<int, int> arr1, arr2, sum, ji;
    cin >> num1;
    for (int i = 0;i < num1;i++)
    {
        cin >> xi >> zhi;
        arr1[zhi] = xi;
    }
    cin >> num2;
    for (int i = 0;i < num2;i++)
    {
        cin >> xi >> zhi;
        arr2[zhi] = xi;
    }
    map<int, int>::iterator it1, it2;
    for (it1 = arr1.begin();it1 != arr1.end();it1++)
    {
        if (sum.find(it1->first) != sum.end())
            sum.find(it1->first)->second += it1->second;
        else
            sum[it1->first] = it1->second;
    }
    for (it2 = arr2.begin();it2 != arr2.end();it2++)
    {
        if (sum.find(it2->first) != sum.end())
            sum.find(it2->first)->second += it2->second;
        else
            sum[it2->first] = it2->second;
    }
    for (it1 = arr1.begin();it1 != arr1.end();it1++)
    {
        for (it2 = arr2.begin();it2 != arr2.end();it2++)
        {
            t = it1->first + it2->first;
            if (ji.find(t) != ji.end())
                ji.find(t)->second += it1->second*it2->second;
            else
                ji[t] = it1->second*it2->second;
        }
    }
    int count = 0, flag = 0;
    it2 = ji.end();
    int len = ji.size();
    while (len--)
    {
        it2--;
        if (it2->second != 0) {
            if (!flag)
            {
                cout << it2->second << " " << it2->first;
                flag = 1;
            }
            else
                cout << " " << it2->second << " " << it2->first;
            count++;
        }
    }
    if (!count)
        cout << "0 0" << endl;
    else
        cout << endl;
    count = 0;
    flag = 0;
    it1 = sum.end();
    len = sum.size();
    while (len--)
    {
        it1--;
        if (it1->second != 0) {
            if (!flag) {
                cout << it1->second << " " << it1->first;
                flag = 1;
            }
            else
                cout << " " << it1->second << " " << it1->first;
            count++;
        }
    }
    if (!count)
        cout << "0 0" << endl;
    else
        cout << endl;
    return 0;
}

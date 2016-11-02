#include <iostream>
#include <map>
using namespace std;


int missingNum(int *a,int n)
{
    map<int,int> map;
    for (int i=0; i < n ;i++)
    {
        map[a[i]] = 1;
    }
    for (int j=1; j< n+1; j++)
    {
        if(map[j] == 0) {
            cout<< j << " ";
        }
    }
    return 0;
}

int main()
{
    int a[]={1,2,3,7,4,5,6,9,11,8,13,10};
    int n=sizeof(a)/sizeof(a[0]);
    missingNum(a,n);
    return 0;
 
}
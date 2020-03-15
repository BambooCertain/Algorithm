#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
const int maxn = 10000;

int arr[maxn];
int x;
int anspos = -1;
int main()
{
    for(int i = 1 ; i <= 1000 ; ++ i) arr[i] = i;
    scanf("%d",&x);
    int l = 1 , r = 1000;    // 二分检索算法
    while(r >= l)
    {
        int mid = (l + r) >> 1;
        if(arr[mid] >= x)
        {
            if(arr[mid] == x) anspos = mid;
            r = mid - 1; 
        }
        else
        {
            l = mid + 1;
        }
        
    }
    printf("%d\n",anspos);
}


/*
输入样例:
200
1001



*/
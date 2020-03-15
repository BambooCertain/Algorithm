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
    for(int i = 1 ; i <= 1000 ; ++ i) // 遍历算法
    {
        if(x == arr[i])
            anspos = i;
    }
    printf("%d\n",anspos);
}
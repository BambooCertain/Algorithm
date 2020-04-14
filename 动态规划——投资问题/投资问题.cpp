#include<cstdio>
#include<string.h>
#include<algorithm>
#include<iostream>
using namespace std;


int n, m; // n代表项目的数量 , m代表投资的金额
int val[1000][1000]; // 用户存储给第i个项目投资x万元，能够获得val[i][x]万元的收益
int dp[1000][1000] = {0}; // dp[i][j]表示到第i个项目的时候已经花费了j万元的最大收益
int main()
{
	
	scanf("%d %d", &n, &m); 
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 0; j <= m; ++j)
		{
			scanf("%d", &val[i][j]); // 对第i个项目投资j万元的收益为val[i][j]
		}
	}
	
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 0; j <= m; ++j)
		{
			for (int k = 0; j + k <= m; ++k)
			{
				dp[i][j + k] = max(dp[i - 1][j] + val[i][k], dp[i][j + k]);
				/*
				我们在前i个项目已经花了j+k万元
				在第i个项目花了k万元
				dp[i][j + k] 就可以后 dp[i - 1][j] + val 转移得到
				所以有转移方程式：dp[i][j + k] = max(dp[i - 1][j] + val[i][k], dp[i][j + k]);
				*/
			}
		}
	}
	cout << dp[n][m] << endl;
	return 0;
}


/*
样例输入：
4 5
0 11 12 13 14 15
0 0 4 10 15 20
0 2 10 30 32 40
0 20 21 22 23 24
样例输出：
61
*/
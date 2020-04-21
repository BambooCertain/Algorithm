#include<cstdio>
#include<string.h>
#include<algorithm>
#include<cmath>
#include<iostream>
#include<vector>
#include<queue>
#include<set>
#include<map>
#include<cctype>
#define ios ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define mem(a,x) memset(a,x,sizeof(a))
#define lson rt<<1,l,mid
#define rson rt<<1|1,mid + 1,r
#define P pair<int,int>
#define ull unsigned long long
using namespace std;
typedef long long ll;
const int maxn = 2e5 + 10;
const ll mod = 998244353;
const int inf = 0x3f3f3f3f;
const long long INF = 0x3f3f3f3f3f3f3f3f;
const double eps = 1e-7;

inline ll read()
{
	ll X = 0, w = 0; char ch = 0;
	while (!isdigit(ch)) { w |= ch == '-'; ch = getchar(); }
	while (isdigit(ch)) X = (X << 3) + (X << 1) + (ch ^ 48), ch = getchar();
	return w ? -X : X;
}

int cnt[1000][1000] , s[1000][1000];
int p[1000];
int n;
int main()
{
	n = read();
	for (int i = 0; i <= n; ++i)
	{
		p[i] = read();  cnt[i][i] = 0;
	}
	for (int len = 2; len <= n; ++len)
	{
		for (int i = 1; i + len - 1 <= n; ++i)
		{
			int j = i + len - 1;
			cnt[i][j] = inf;
			s[i][j] = 0;
			for (int k = i; k < j; ++k)
			{
				int tmp = cnt[i][k] + cnt[k + 1][j] + p[i - 1] * p[k] * p[j];
				if (tmp < cnt[i][j])
				{
					cnt[i][j] = tmp;
					s[i][j] = k;
				}
			}
		}
	}
	cout << cnt[1][n] << endl;
	return 0;
}
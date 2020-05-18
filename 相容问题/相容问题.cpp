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
const int maxn = 5e5 + 10;
const ll mod = 998244353;
const int inf = 0x3f3f3f3f;
const long long INF = 0x3f3f3f3f3f3f3f3f;
const double eps = 1e-7;

struct node
{
	int s, e;
	// s代表节目的开始时间， e代表结束时间
}p[maxn];
int n;
int cmp(node& a, node& b)
{
	return a.e < b.e;
}

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i)
	{
		scanf("%d %d", p[i].s, p[i].e);
	}
	sort(p + 1, p + 1 + n, cmp);
	int ans = 0, end = 0;
	for (int i = 1; i <= n; ++i)
	{
		if (p[i].s >= end)
		{
			ans++;
			end = p[i].e;
		}
	}
	printf("%d\n", ans);

	return 0;
}
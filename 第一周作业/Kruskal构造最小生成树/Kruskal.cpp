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
#include<stack>
#define ios ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define mem(a,x) memset(a,x,sizeof(a))
#define lson rt<<1,l,mid
#define rson rt<<1|1,mid + 1,r
#define P pair<int,int>
#define ull unsigned long long
using namespace std;
typedef long long ll;
const int maxn = 1e6 + 10;
const ll mod = 998244353;
const int inf = 0x3f3f3f3f;
const long long INF = 0x3f3f3f3f3f3f3f3f;
const double eps = 1e-7;

int n;

int main()
{
	int a = 1, b = 1;
	int n = 2;
	while (b <= 10000)
	{
		int t = b;
		b = a + b;
		a = t;
		n++;
	}
	printf("%d %d\n", a, n);
	return 0;
}
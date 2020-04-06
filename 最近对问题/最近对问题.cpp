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




int n, m, k;
int arr[maxn], pos[maxn], res = 0, cnt[maxn] = {0}, ans2[maxn] , ans1[maxn];

struct point {
	double x, y;
}p[maxn],tmp[maxn];


int cmp1(point& a, point& b)
{
	return a.x < b.x;
}
int cmp2(point& a, point& b)
{
	return a.y < b.y;
}

double get_dis(point p1, point p2)
{
	return sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));
}

int EffcientClosestPair(point p[], int l, int r)
{
	if (r == l) return inf;
	if (r - l == 1)
	{
		return get_dis(p[l], p[r]);
	}
	if(r - l == 2)
	{
		double d1 = get_dis(p[l], p[r]);
		double d2 = get_dis(p[l], p[l + 1]);
		double d3 = get_dis(p[l + 1], p[r]);
		return min(d1, min(d2, d3));
	}
	int mid = (r + l) >> 1;
	double d = min(EffcientClosestPair(p, l, mid) , EffcientClosestPair(p, mid + 1, r));
	int ql = l , qr = r;
	while (p[ql].x < p[mid].x - d && ql <= r) ++l;
	while (p[qr].x > p[mid].x + d && qr >= l) --r;
	for (int i = l; i <= r; ++i)
	{
		tmp[i] = p[i];
	}
	sort(tmp + l, tmp + r + 1, cmp2);
	for (int i = l; i <= r; ++i)
	{
		for (int j = l + 1; j <= r; ++j)
		{
			if (tmp[j].y - tmp[i].y >= d)
				break;
			else
				d = min(d, get_dis(tmp[i], tmp[j]));
		}
	}
	return d;

}

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i)
	{
		scanf("%lf %lf", &p[i].x, &p[i].y);
	}
	sort(p + 1, p + 1 + n, cmp1);
	cout << EffcientClosestPair(p, 1, n) << endl;
	return 0;
}
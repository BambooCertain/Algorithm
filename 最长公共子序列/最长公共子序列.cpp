#include<cstdio>
#include<string.h>
#include<algorithm>
#include<cmath>
#include<iostream>
#include<vector>
#include<queue>
#include<set>
#include<stack>
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

int len1, len2;
int dp[1000][1000];
string arr, brr;
int res[1000][1000];
void lcs()
{
	for (int i = 0; i <= len1; ++i) dp[i][0] = 0;
	for (int i = 0; i <= len2; ++i) dp[0][i] = 0;
	for (int i = 1; i <= len1; ++i)
	{
		for (int j = 1; j <= len2; ++j)
		{
			if (arr[i] == brr[j])
				dp[i][j] = dp[i - 1][j - 1] + 1;
			else
			{
				if (dp[i - 1][j] > dp[i][j - 1])
				{
					res[i][j] = 1;
					dp[i][j] = dp[i - 1][j];
				}
				else
				{
					res[i][j] = 2;
					dp[i][j] = dp[i][j - 1];
				}
			}
		}
	}
}
string getlcs()
{
	int i = len1, j = len2;
	string ans = "";
	while (i > 0 && j > 0)
	{
		if (!res[i][j])
		{
			ans = arr[i] + ans;
			i--, j--;
		}
		else if (res[i][j] == 1)
		{
			i--; 
		}
		else
		{
			j--;
		}
	}
	return ans;
}

int main()
{
	cin >> arr >> brr;
	len1 = arr.size(), len2 = brr.size();
	arr = " " + arr;
	brr = " " + brr;
	lcs();
	cout << "最长公共字串长度： " << dp[len1][len2] << endl;
	cout << "最长公共字串： " << getlcs() << endl;
	return 0;
}
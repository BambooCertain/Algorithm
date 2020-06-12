#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;


const int maxn = 1e5 + 10;
double minlen = 1e5;
double x[maxn], r[maxn]; 
// x存储每个圆心的横坐标 ， r存储每个圆的半径 ，
// 由于x数组为全局变量，因此初始化为0，因此第一个圆的横坐标默认为0，因此在计算最小圆排列长度的时候还需要注意加上第一个圆的半径
double bestR[maxn]; // 存储最优的圆排列的半径顺序
int n;

double get_center(int t)
{
	double tmp = 0;
	for (int i = 1; i < t; ++i)
	{
		double val = x[i] + 2.0 * sqrt(r[t] * r[i]); //. 目标圆T有可能能够和排在它之前的任意一个圆相切，因此需要以一判断取最大值
		tmp = max(tmp, val);
	}
	return tmp;
}

void get_ans()
{
	double minn = 0, maxx = 0; // 计算最优圆排列的最左端 和 最右端
	for (int i = 1; i <= n ; ++i)
	{
		if (x[i] - r[i] < minn) minn = x[i] - r[i];
		if (x[i] + r[i] > maxx) maxx = x[i] + r[i];
	}
	if (maxx - minn < minlen)
	{
		minlen = maxx - minn; // 更新最小圆排列
		for (int i = 1; i <= n ; ++i)
		{
			bestR[i] = r[i];
		}
	}
}


void dfs(int pos)
{
	if (pos == n + 1)
	{
		get_ans();
	}
	else
	{
		for (int i = pos; i <= n; ++i)
		{
			swap(r[pos], r[i]);//构造全排列
			double X_pos = get_center(pos);//获取当前
			if (X_pos + r[pos] + r[1] < minlen) //计算当前情况下的圆排列长度，如果长度大于最小圆排列长度，由此圆排列所构成的圆排列长度一定不满足最小圆排列，可放弃搜索
			{
				x[pos] = X_pos;
				dfs(pos + 1);
			}
			swap(r[pos], r[i]); //构造全排列
		}
	}
}


int main()
{
	cout << "输入圆的个数：" << endl;
	cin >> n;
	cout << "依次输入圆的半径" << endl;
	for (int i = 1; i <= n; ++i)
	{
		cin >> r[i];
	}
	for (int i = 1; i <= n; ++i)
	{
		cout << "第" << i << "个圆的半径为：" << r[i] << endl;
	}
	dfs(1);
	cout << "最小圆排列的长度为：" << minlen << endl;
	cout << "最优原排列的顺序对应的半径分别为：";
	for (int i = 1; i <= n; ++i)
	{
		cout << bestR[i] << " ";
	}
	cout << endl;
	return 0;
}
#include<stdio.h>
#include<algorithm>
#include<iostream>
using namespace std;
int a[100010];
void swap(int& x, int& y) {
    int temp = x;
    x = y;
    y = temp;
}
int random(int l, int r) {//返回一个在[l,r]范围内的随机整数
    return rand() % (r - l + 1) + l;
}
int find_kth(int l, int r, int k) {
    if (l == r)return a[l];//递归边界
    int temp = a[random(l, r)];//随机选取主元
    int cnt = 0;//计比主元大的个数
    int i = l, j = r;
    while (i <= j) {
        while (a[i] > temp&& i <= j)i++, cnt++;
        while (a[j] <= temp && i <= j)j--;
        if (i < j) {
            swap(a[i], a[j]);
            cnt++;
        }
        i++, j--;
    }
    if (cnt >= k) {//若k<=cnt，就在左半段中递归寻找第k大
        return find_kth(l, l + cnt - 1, k);
    }
    else {//否则在就在右半段中递归寻找第k-cnt大的数
        return find_kth(l + cnt, r, k - cnt);
    }
}
int main() {
    int n; cin >> n;
    for (int i = 1; i <= n; i++)cin >> a[i];
    int k; cin >> k;
    cout << find_kth(1, n, k) << endl;
}

#include<iostream>
#include<algorithm>
#include<memory.h>
using namespace std;

const int inf = 0x3f3f3f3f;                               //inf代表无穷大，在本算法中，如果path[i][j] == inf ，那么说明从节点i出发无法到达节点j
int n, m;
int p[1000][1000];                                       //用来维护图中任意两点之间的最短距离


void Floyd(int n ,int m ,int path[][1000])
{
    for(int k = 1 ; k <= n ; ++ k)                               //枚举中转点，通过中转点对i，j进行松弛操作
    {
        for(int i = 1 ; i <= n ; ++ i)                           //枚举起点
        {
            for(int j = 1 ; j <= n ; ++ j)                       //枚举终点
            {
                if(path[i][k] + path[k][j] < path[i][j])         // 如果通过k节点使得 path[i][k] + path[k][j] < path[i][j] 则说明经过k节点会使得i，j之间的距离更短，更新最短距离
                    path[i][j] = path[i][k] + path[k][j];
            }
        }
    }
}



int main()
{

    memset(p , inf , sizeof p);                         //对图path进行初始化
    cin >> n >> m;                                      //获取节点个数和边的条数
    for(int i = 1 ; i <= n ; ++ i) p[i][i] = 0;         //一个节点到它本身的最小距离肯定是0，这里我们直接修改就好了   
    for(int i = 1 ; i <= m ; ++ i)
    {
        int u ,v , val;
        cin >> u >> v >> val;                           //获取单向边的信息
        p[u][v] = min(p[u][v] , val);                   //因为我们要求图中任意两点的最小距离，因此对于点i，j之间的路线，我们只要记录最小值即可
    }
    Floyd(n , m , p);                                    //进行Floyd
    cout << "最短距离矩阵：" << endl;
    for(int i = 1 ; i <= n ; ++ i)
    {
        for(int j = 1 ; j <= n ; ++ j)
        {
            if(p[i][j] == inf) cout << -1;              //如果p[i][j] == inf , 说明从i节点出发，无法到达j节点，这里我们用-1表示无法到达
            else cout << p[i][j];
            if(j == n) cout << endl;
            else cout << " ";
        }
    }
    return 0;
}

/*
样例：

4 8
1 2 2
2 3 3
1 3 6
3 1 7
1 4 4
4 1 5
3 4 1
4 3 12


*/
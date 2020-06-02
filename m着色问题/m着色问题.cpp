#include <iostream>
#include <cstdio>

using namespace std;

int n,m;
int a=1,b=1;
int cnt=0;
int graph[20][20]={0};
int color[20]={0};

bool check(int c){
    for(int k=1;k<=n;k++){
        if(graph[c][k]&&color[c]==color[k]){
            return false;
        }
    }
    return true;
}

void dfs(int cur){
    if(cur>n){
        for(int i=1;i<=n;i++){
            printf("%d ",color[i]);
        }
        cnt++;
        printf("\n");
    }else{
        for(int i=1;i<=m;i++){
            color[cur]=i;
            if(check(cur)){
                dfs(cur+1);
            }
            color[cur]=0;
        }
    }
}

int main()
{
    scanf("%d %d",&n,&m);
    while(scanf("%d %d",&a,&b)!=EOF&&a!=0&&b!=0){
        graph[a][b]=1;
        graph[b][a]=1;
    }
    dfs(1);
    if(cnt > 0)
    {
        printf("Total=%d",cnt);
    }
    else
    {
        printf("NO\n");
    }
    
    return 0;
}
/*
样例输入：
5 4
1 3
1 2
1 4
2 3
2 4
2 5
3 4
4 5
0 0

样例输出：
1 2 3 4 1 
1 2 3 4 3 
1 2 4 3 1 
1 2 4 3 4 
1 3 2 4 1 
1 3 2 4 2
1 3 4 2 1 
1 3 4 2 4 
1 4 2 3 1 
1 4 2 3 2 
1 4 3 2 1 
1 4 3 2 3 
2 1 3 4 2 
2 1 3 4 3 
2 1 4 3 2 
2 1 4 3 4 
2 3 1 4 1 
2 3 1 4 2 
2 3 4 1 2 
2 3 4 1 4 
2 4 1 3 1 
2 4 1 3 2 
2 4 3 1 2 
2 4 3 1 3 
3 1 2 4 2 
3 1 2 4 3 
3 1 4 2 3 
3 1 4 2 4 
3 2 1 4 1 
3 2 1 4 3 
3 2 4 1 3 
3 2 4 1 4 
3 4 1 2 1 
3 4 1 2 3 
3 4 2 1 2 
3 4 2 1 3 
4 1 2 3 2 
4 1 2 3 4 
4 1 3 2 3 
4 1 3 2 4 
4 2 1 3 1 
4 2 1 3 4 
4 2 3 1 3 
4 2 3 1 4 
4 3 1 2 1 
4 3 1 2 4 
4 3 2 1 2 
4 3 2 1 4 
Total=48


*/

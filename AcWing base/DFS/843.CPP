#include <iostream>
using namespace std;
const int N = 20;
char g[N][N];
bool col[N], dg[N], udg[N];
int n;
void dfs(int u){
    if(u==n){
        for(int i=0;i<n;i++) puts(g[i]);
        puts("");
        return;
    }
    for(int i=0;i<n;i++){
        //对角线 斜对角线 没有访问过的话(u-i+n避免出现负数情况加个偏移量)
        if(!col[i]&&!dg[u+i]&&!udg[i-u+n]){
            g[u][i] = 'Q';
            col[i]=dg[u + i]=udg[i - u + n]=true;
            dfs(u+1);
            col[i]=dg[u + i]=udg[i - u + n]=false;
            g[u][i]='.';
        }
    }
}
int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            g[i][j] = '.';
    dfs(0);
    return 0;
}

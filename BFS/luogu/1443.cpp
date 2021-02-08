#include<iostream>
#include<algorithm>
#include<cstring>
#include<queue>
using namespace std;

typedef pair<int,int> PII;

const int N = 401;
int g[N][N];
int d[N][N];
int n, m;
int sx,sy;
queue<PII> q;

void dfs(){
    memset(d,-1,sizeof d);
    d[sx][sy] = 0;
    q.push({sx,sy});
   //方向问题
    //int dx[] = {-2,-1,1,2,2,1,-1,-2},dy[]={1,2,2,1,-1,-2,-2,1};
    int dx[] = {2,-2,2,-2,-1,1,-1,1},dy[]={1,1,-1,-1,2,2,-2,-2};
    while(q.size()){
        PII t = q.front();
        q.pop();
        int x = t.first,y=t.second;
        for(int i=0;i<8;i++){
            int a = x+dx[i],b=y+dy[i];
            if(a>=1&&a<=n&&b>=1&&b<=m&&d[a][b]==-1){
                q.push({a,b});
                d[a][b]=d[x][y]+1;
            }
        }
    }
}
int main()
{
    cin >> n >> m >> sx >> sy;
    dfs();
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <=m; j++)
            //cout << d[i][j] << ' ';
            printf("%-5d",d[i][j]);
        puts("");
    }
    return 0;
}
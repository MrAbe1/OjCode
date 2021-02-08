#include<iostream>
#include<queue>
#include<cstring>
#include<algorithm>

using namespace std;
typedef pair<int,int> PII;
const int N=301;

int d[N][N];
int sx,sy,ex,ey;
int n;

int dfs(){
    memset(d,-1,sizeof d);
    queue<PII> q;
    q.push({sx,sy});
    d[sx][sy]=0;
    //方向问题 逆时针 可以  顺时针不行 
    //int dx[] = {-2,-1,1,2,2,1,-1,-2},dy[]={1,2,2,1,-1,-2,-2,1} 
    int dx[] = {2,1,-1,-2,-2,-1, 1, 2},dy[]={1,2,2 ,1, -1,-2,-2,-1};
    while(q.size()){
        PII t = q.front();
        q.pop();
        int x = t.first,y = t.second;
        for(int i=0;i<8;i++){
            int a = x+dx[i],b=y+dy[i];
            if(a>=0&&a<=n&&b>=0&&b<=n&&d[a][b]==-1){
                q.push({a,b});
                d[a][b] = d[x][y]+1;
            }
        }
    }
    return d[ex][ey];
}

int main(){
    int t;
    cin>>t;
    while(t--){
        cin>>n;
        cin>>sx>>sy>>ex>>ey;
        cout<<dfs()<<endl;
    }
}

#include<cstring>
#include<iostream>
#include<algorithm>

using namespace std;

const int N=510;

int n,m;
int g[N][N];
int dist[N];
//存储当前点到1号点的距离是否确定下来了
bool st[N];

int dijkstra(){
    memset(dist,0x3f,sizeof dist);
    dist[1]=0;
    //循环n-1次，因为1号点已经确定了
    for(int i=0;i<n-1;i++){
        int t =-1;
        //每次从所有未确定点中，找到最小的一个点更新其他点
        //这里j从2开始也可，从1开始的话，用1更新1不影响
        for(int j=1;j<=n;j++){
            if(!st[j]&&(t==-1||dist[t]>dist[j]))
            t = j;
        }
        //如果所有不确定点中最小的点找到了n，那么可以提前break掉
        //if(t==n) break;
        //用最小的距离去更新其他点
        for(int j=1;j<=n;j++){
            dist[j] = min(dist[j],dist[t]+g[t][j]);
        }
        st[t] = true;
    }
    if(dist[n] == 0x3f3f3f3f)
    return -1;
    return dist[n];
}

int main(){
    cin>>n>>m;
    memset(g,0x3f,sizeof g);
    while(m--){
        int a,b,c;
        cin>>a>>b>>c;
        //去除重边，选最小的边,自环不影响最短路
        g[a][b] = min(g[a][b],c);
    }
    cout<<dijkstra()<<endl;
    return 0;
}

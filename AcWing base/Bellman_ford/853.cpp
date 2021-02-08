#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;
const int N=510,M=10010;

int n,m,k;
int dist[N],backup[N];

struct Edge{
    int a,b,w;
}edges[M];

int bellman_ford(){
    memset(dist,0x3f,sizeof dist);
    dist[1]=0;

    for(int i=0;i<k;i++){
        //每次用上一次的dist进行更新
        memcpy(backup,dist,sizeof dist);
        for(int j=0;j<m;j++){
            int a = edges[j].a, b = edges[j].b, w = edges[j].w;
            dist[b] = min(dist[b],backup[a] + w);
        }
    }
    //dist[n] 可能会被更新，但是依旧是一个无穷大的数字，所以可以return -1
    if(dist[n] > 0x3f3f3f3f/2 ) return -1;
    return dist[n];
}

int main(){
    cin>>n>>m>>k;

    for(int i=0;i<m;i++){
        int a,b,w;
        cin>>a>>b>>w;
        edges[i] = {a,b,w};
    }

    int t = bellman_ford();
    if(t==-1) puts("impossible");
    else cout<<t<<endl;
    return 0;
}

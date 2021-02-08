#include<iostream>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;

const int N=100010;

int n,m;
//e[]存储点的编号，ne[]存储点的下标idx
int h[N],e[N],ne[N],idx;
int d[N];

void add(int a,int b){
    e[idx]=b,ne[idx]=h[a],h[a]=idx++;
}
int bfs(){
    queue<int> q;
    memset(d,-1,sizeof d);
    d[1]=0;
    q.push(1);

    while(q.size()){
        int t = q.front();
        q.pop();
        for(int i=h[t];i!=-1;i=ne[i]){
            int j = e[i];
            if(d[j]==-1){
                q.push(j);
                d[j]=d[t]+1;
            }
        }
    }
    return d[n];
}
int main(){
    cin>>n>>m;
    //初始化头结点
    memset(h,-1,sizeof h);
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        add(a,b);
    }
    cout<<bfs()<<endl;
    return 0;
}
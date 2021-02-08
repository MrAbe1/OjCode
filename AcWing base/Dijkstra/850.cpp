
#include<iostream>
#include<cstring>
#include<queue>
#include<algorithm>

using namespace std;
typedef pair<int,int> PII;

const int N=1e6+10;

int n,m;
//w[N],存储权重
int h[N],w[N],e[N],ne[N], idx;
int dist[N];
bool st[N];

//在表头为a的邻接表添加a-b的边 权重为c 
void add(int a,int b,int c){
    e[idx]=b,w[idx]=c,ne[idx]=h[a],h[a]=idx++;
}

int dijkstra(){
    memset(dist,0x3f,sizeof dist);
    dist[1]=0;
    //修改为小根堆,按照第一个元素排序，第一个位置存储dist，第二个位置存储序号
    priority_queue<PII,vector<PII>,greater<PII>>heap;
    heap.push({0,1});
    
    while(heap.size()){
        auto t = heap.top();
        heap.pop();
        
        int ver = t.second,distance = t.first;
        if(st[ver]) continue;
        st[ver] = true;
        
        //更新其他和ver有连接的其他点
        for(int i=h[ver];i!=-1;i=ne[i]){
            int j = e[i];
            //w[i] 存储到b的权重 
            if(dist[j] > dist[ver]+w[i]){
                dist[j] = dist[ver]+w[i];
                heap.push({dist[j],j});
            }
        }
    }
    if(dist[n]==0x3f3f3f3f) return -1;
    return dist[n];
    
}

int main(){
    cin>>n>>m;
    memset(h,-1,sizeof h);
    while(m--){
        int a,b,c;
        cin>>a>>b>>c;
        //有重边不需要考虑，因为算法会保证每次取最小的边（heap），不需要单独处理
        add(a,b,c);
    }
    cout<<dijkstra()<<endl;
    return 0;
}
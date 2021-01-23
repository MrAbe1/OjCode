#include<iostream>
#include<algorithm>
using namespace std;
const int N=100010;
int n,m;
int h[N],cnt;
//小根堆
void down(int u){
    int t =u;
    //当左孩子比当前结点小，交换左孩子和当前结点，同理
    if(u*2<=cnt &&h[u*2]<h[t]) t = u*2;
    if(u*2+1<=cnt &&h[u*2+1]<h[t]) t = u*2+1;
    if(u!=t){
        swap(h[u],h[t]);
        down(t);
    }
}

int main(){
    cin>>n>>m;
    //建一个堆
    for(int i=1;i<=n;i++) cin>>h[i];
    cnt = n;
    //把堆进行排序
    for(int i=n/2;i;i--) down(i);
    while(m--){
        cout<<h[1]<<" ";
        h[1] = h[cnt--];
        down(1);
    }
    puts("");
    return 0;
}
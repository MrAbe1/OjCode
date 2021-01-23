#include<iostream>
using namespace std;
const int N=500010;
int n,m;
int p[N],d[N];
//d[x]表示x与父节点的距离
int find(int x){
    if(p[x]!=x){

        int t = find(p[x]);
        d[x] +=d[p[x]];
        p[x]=t;

    }
    return p[x];
}
int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++) p[i]=i;
    int res=0;
    while(m--){
        int t,x,y;
        cin>>t>>x>>y;
        if(x>n||y>n) res++;
        else{
            int px=find(x),py=find(y);
            if(t==1){
                // x y是同类，x,y在一个集合中，且x，y的距离差不满足为0的情况
                if(px==py &&(d[x]-d[y])%3) res++;
                else if(px!=py){//把x或者y加入集合中
                    p[px] = py;
                    d[px]= d[y]-d[x];
                }
            }else//x吃y
            {
                //x y在一个集合内，但是距离差 mod 3不是1 即x吃不了y
                if(px==py&&(d[x]-d[y]-1)%3) res++;
                else if(px!=py){
                    p[px]= py;
                    d[px] = d[y]+1-d[x];
                }
            }
        }
    }
    cout<<res<<endl;
    return 0;
    
}
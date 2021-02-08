#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;
//邻接表的方式存储图
const int N=100010,M=N*2;

int n;
int h[N],e[M],ne[M],idx;
int ans = N;
bool st[N];

//添加一条a连向b的边
void add(int a,int b){
e[idx]=b,ne[idx]=h[a],h[a]=idx++;
}
int  dfs(int u){
    //当前结点被访问过
    st[u] = true;
    int sum = 1,res = 0;
    for(int i = h[u];i!=-1;i=ne[i]){
        int j = e[i];
        if(!st[j]) {
            st[j]=true;
            int s =dfs(j);
            res = max(res,s);
            sum+=s;
        }  
    }
    res = max(res,n-sum);
    ans = min(ans,res);
    return sum;
}
int main(){
    cin>>n;
    memset(h,-1,sizeof h);
    for(int i=0;i<n-1;i++){
        int a,b;
        cin>>a>>b;
        add(a,b),add(b,a);
    }
    dfs(1);
    cout<<ans<<endl;
    return 0;
}
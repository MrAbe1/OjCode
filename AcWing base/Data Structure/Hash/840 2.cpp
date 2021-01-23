//拉链法
#include<iostream>
#include<cstring>
using namespace std;
const int N=100003;
int h[N],e[N],ne[N],idx;
void insert(int x){
    //先找到合适的位置，在合适的位置插入，在表头插入
    //这个时候h[]都作为头结点使用
    int k= (x%N+N)%N;
    e[idx]=x;
    ne[idx]=h[k];
    h[k]=idx++;
}
bool find(int x){
    int k = (x%N+N)%N;
    //尾结点为-1
    for(int i=h[k];i!=-1;i=ne[i]){
        if(e[i]==x)
        return true;
    }
    return false;
}
int main(){
    int n;
    cin>>n;
    memset(h,-1,sizeof h);
    while(n--){
        char op[2];
        int x;
        cin>>op>>x;
        if(*op=='I') insert(x);
        else{
            if(find(x)) puts("Yes");
            else puts("No");
        }
    }
    return 0;
}
//开放寻址法
#include<iostream>
#include<cstring>
using namespace std;
const int N=200003,null = 0x3f3f3f3f;
int h[N];
//找一个可以放x的为null的下标
int find(int x){
    //防止负数的出现，保证余数为正数
    int t =(x%N+N)%N;
    while(h[t]!=null &&h[t]!=x){
        t++;
        //到末尾了 从头开始
        if(t==N) t=0;
    }
    return t;
}
int main(){
    memset(h,0x3f,sizeof h);
    int n;
    cin>>n;
    while(n--){
        char op[2];
        int x;
        cin>>op>>x;
        if(*op=='I') h[find(x)] =x;
        else{
            //如果可以放x的位置的存的是null
            if(h[find(x)]==null)
            puts("No");
            else puts("Yes");
        }
    }
    return 0;

}
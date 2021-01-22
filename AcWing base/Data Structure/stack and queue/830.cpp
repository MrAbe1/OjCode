#include<iostream>
using namespace std;
const int N=100010;
int stk[N],tt;
int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        //单调栈，里面的元素都是单调的
        //当栈不为空，tt--找到第一个比tt小的元素
        while(tt&&stk[tt]>=x) tt--;
        //当栈为空的时候没有找到目标元素，输出-1
        if(!tt) cout<<"-1 ";
        else
        cout<<stk[tt]<<' ';
        //把当前的元素压进栈中
        stk[++tt] =x;

    }
    return 0;
}
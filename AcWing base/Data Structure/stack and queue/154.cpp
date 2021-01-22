#include<iostream>
using namespace std;
const int N=1000010;
//q存放下标,a存放原始的值
int a[N],q[N];
int main(){
    int n,k;
    //k为滑动窗口的大小
    cin>>n>>k;
    for(int i=0;i<n;i++) cin>>a[i];
    int hh=0,tt=-1;
    //先找最小元素
    for(int i=0;i<n;i++){
        //升序排列
        //当前值如果小于等于队尾元素，那么意味着队尾元素用不到了,出队
        //注意，这里用while而不是if，一直到当前值大于队尾元素，停止，然后当前值入队
        while(hh<=tt&&a[i]<=a[q[tt]]) tt--;
        //当队首元素的下标超过滑动窗口大小
        if(hh<=tt&&q[hh]<i-k+1) hh++;
        //先入队，再输出
        q[++tt]=i;
        //前k-1(下标0——k-2)个元素不用输出
        if(i>k-2) cout<<a[q[hh]]<<" ";
        }
        puts("");
    
    //再找最大元素
     hh=0,tt=-1;
    for(int i=0;i<n;i++){
        //降序排列
        //当前值如果大于等于队尾元素，那么意味着队尾元素用不到了,出队
        while(hh<=tt&&a[i]>=a[q[tt]]) tt--;
        //当队首元素的下标超过滑动窗口大小
        if(hh<=tt&&q[hh]<i-k+1) hh++;
        //前k-1(下标0——k-2)个元素不用输出
        //先入队，再输出
        q[++tt]=i;
        if(i>k-2) cout<<a[q[hh]]<<" ";
        }
        puts("");

    return 0;

}
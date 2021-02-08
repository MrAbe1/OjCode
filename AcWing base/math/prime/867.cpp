#include<iostream>
using namespace std;
void divide(int n){
    //首先O(n)的时间复杂度肯定会超时
    //n 最多只有一个大于sqrt(n)的质数  反证法
    //i肯定是质数，从2——i-1 循环过来，n不断的剔除自身含有的2——i-1的约数
    //任何一个数都可以表示成p1^k1p2^k2p3^k3……的形式，p1<p2<p3,且其为质数
    //从小到大枚举，会不断的把相关的p1，k1 找出来的
    for(int i=2;i<=n/i;i++){
        if(n%i==0){
            int s=0;
            while(n%i==0){
                s++;
                n/=i;
            }
            printf("%d %d\n",i,s);
        }
    }
    if(n>1) printf("%d %d\n",n,1);
    puts("");
}
int main(){
    int n;
    cin>>n;
    while(n--){
        int x;
        cin>>x;
        divide(x);
    }
    return 0;
}

#include<iostream>
using namespace std;
const int N=101;
int a[N];
bool is_prime(int x){
    if(x<2) return false;
    //这个地方不要写成i*i<=x 因为会溢出，然后导致超时
    //注意x的max是2^32  约等于10^9  o（n）的时间复杂度肯定会超时的
    for(int i=2;i<=x/i;i++)
        if(x%i==0) return false;
     return true;
}
int main(){
    int n;
    cin>>n;
    while(n--){
        int x;
        cin>>x;
        if(is_prime(x))
         puts("Yes");
        else puts("No");
    }
    return 0;
}

#include<iostream>
#include<algorithm>
using namespace std;
typedef unsigned long long ULL;
const int N=100010,P=131;
int n, m;
char str[N];
//p[i]存储幂P的i次方
ULL h[N],p[N];
//计算l到r的hash值
ULL get(int l,int r){
    return h[r]-h[l-1]*p[r-l+1];
}
int main(){
    cin>>n>>m;
    cin>>str+1;
    p[0]=1;
    //h[]计算字符串的前缀hash
    //p进制下的字符串"ABCD"对应的十进制和即为其hash
    for(int i=1;i<=n;i++){
        h[i]= h[i-1]*P+str[i];
        p[i] = p[i-1]*P;
    }
    while(m--){
        int l1,r1,l2,r2;
        cin>>l1>> r1>>l2>>r2;
        if(get(l1,r1)==get(l2,r2))
        puts("Yes");
        else
        puts("No");
    }
    return 0;
}
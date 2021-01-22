#include<iostream>
using namespace std;
const int N=100010;
const int M=1000010;
char p[N],s[M];
int ne[N];
int main(){
    int n,m;
    //下标均从1开始
    cin>>n>>p+1>>m>>s+1;
    //求next数组，初始，next[1] = 0 过程类似于kmp的匹配过程
    //ne[j]存储着最大相同前缀和后缀的长度，存储着下一次开始的前一位下标
    for(int i=2,j=0;i<=n;i++){
        while(j&&p[i]!=p[j+1]) j=ne[j];
        if(p[i]==p[j+1]) j++;
        ne[i]=j;
    }
    //kmp匹配过程
    for(int i=1,j=0;i<=m;i++){
        //当s[i]与p[j+1]个进行预匹配
        while(j&&s[i]!=p[j+1]) j=ne[j];
        if(s[i]==p[j+1]) j++;
        if(j==n){
            //输出模式串在匹配串中的下标，原题是从0开始
            cout<<i-n<<' ';
            //已经匹配成功后，也可以理解为1-j位置匹配成功之后，j+1肯定不匹配，只不过这是最特殊的情况
            //那么j需要后退到ne[j]继续匹配
            j = ne[j];
        }
    }
    return 0;
}
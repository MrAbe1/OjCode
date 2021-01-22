#include<iostream>
#include<cstring>
using namespace std;
const int N=1000010;
char s[N],p[N];
int ne[N];
int main(){
    cin>>s+1>>p+1;
    int len_s =strlen(s+1);
    int len_p = strlen(p+1);
    //计算ne数组
    for(int i=2,j=0;i<=len_p;i++){
        while(j&&p[i]!=p[j+1]) j=ne[j];
        if(p[i]==p[j+1]) j++;
         ne[i] = j;
    }
    //kmp匹配
    for(int i=1,j=0;i<=len_s;i++){
        while(j&&s[i]!=p[j+1]) j=ne[j];
        if(s[i]==p[j+1]) j++;
        if(j==len_p){
            cout<<i-len_p+1<<endl;
            j=ne[j];
        }
    }
    for(int i=1;i<=len_p;i++)
    cout<<ne[i]<<' ';
    
    return 0;
}
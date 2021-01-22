#include<iostream>
using namespace std;
const int N= 100010;
//son中存储的是下标idx
int son[N][26],cnt[N],idx;//idx =0 既是根节点也是空结点
char str[N];
//插入操作
void insert(char str[]){
    int p=0;
    //str[i]表示判断当前字符串不为'/0'，即是否到了末尾
    for(int i=0;str[i];i++){
        int u = str[i]-'a';
        //当前结点p存在u的子节点，那么p到赋值为孩子结点
        //如果不存在的话，给孩子结点一个下标
        //用son[p][u]是否为0来判断是否有u这个孩子结点
        if(!son[p][u]) son[p][u] = ++idx;
        p = son[p][u];
    }
    //一个字符串循环完成之后，p指向最终的孩子结点，cnt[p]++,意味着
    //这个字符串的数目+1，注意每一个字符串字符的下标都是独一无二的;
    cnt[p]++;
}
//查询操作
int query(char str[]){
    int p = 0;
    //遍历整个字符串，如果没有当前字符的结点，那么意味着没有该结点，中断退出
    for(int i=0;str[i];i++){
        int u = str[i]-'a';
        if(!son[p][u]) return 0;
       //有的话，p继续深入搜索
        p = son[p][u];
    }
    //返回以p结尾的，字符串数目
    return cnt[p];
}
int main(){
    int n;
    cin>>n;
    while(n--){
        char op;
        cin>>op>>str;
        if(op=='I') insert(str);
        else 
        cout<<query(str)<<endl;
    }
    return 0;
}
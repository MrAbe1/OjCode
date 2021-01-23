#include <iostream>
using namespace std;
const int N = 100010;
int p[N];
int n, m;
int find(int a){//找祖宗结点+路径压缩
    //当a不是根节点的时候
    //a的父亲结点为a的父亲结点的父亲结点，最终a直接指向祖宗结点
    if(p[a]!=a) p[a] = find(p[a]);
    return p[a];
}
int main()
{
    cin >> n >> m;
    char op;
    int a, b;
    //初始每个元素就是一个集合，下标从哪0/1开始都可以
    for(int i =1;i<=n;i++)
    p[i]=i;
    while (m--)
    {
        cin >> op >> a >> b;
        if(op =='M') p[find(a)] = find(b);
        else{
            if(find(a)==find(b))
            puts("Yes");
            else
            puts("No");
        }
    }
    return 0;
}
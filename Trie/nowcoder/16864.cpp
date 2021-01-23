#include <iostream>
using namespace std;
const int N = 100010;
char str[64];
int son[N][26], idx;
void insert(char str[])
{
    int p = 0;
    for(int i =0;str[i];i++){
        int u = str[i]-'A';
        if(!son[p][u]) son[p][u] = ++idx;
        p = son[p][u];
    }
}
int main()
{
    while (cin >> str)
    {
        insert(str);
    }
    cout << idx+1 << endl;
}
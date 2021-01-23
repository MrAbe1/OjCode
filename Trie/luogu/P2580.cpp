#include <iostream>
using namespace std;
const int N = 1000010;
int  son[N][26], cnt[N];
int  idx;
int n, m;
char a[N];
void insert(char a[])
{
    int p = 0;
    for (int i = 0; a[i]; i++)
    {
        int u = a[i] - 'a';
        if (!son[p][u])
            son[p][u] = ++idx;
        p = son[p][u];
    }
}
int query(char a[])
{
    int p = 0;
    for (int i = 0; a[i]; i++)
    {
        int u = a[i] - 'a';
        if (!son[p][u])
            return 1;
        p = son[p][u];
    }
    cnt[p]++;
    if (cnt[p] == 1)
        return 0;
    return 2;
}

int main()
{
    cin >> n;
    while (n--)
    {
        cin >> a;
        insert(a);
    }
    cin >> m;
    while (m--)
    {
        cin >> a;
        int t = query(a);
        if (t == 0)
        {
            cout << "OK" << endl;
        }
        else if (t == 1)
        {
            cout << "WRONG" << endl;
        }
        else
        {
            cout << "REPEAT" << endl;
        }
    }
    return 0;
}

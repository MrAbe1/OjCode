#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int inf = 0x3f3f3f3f;
const ll maxn = 1e5 + 10;
string a;
void fun(int index, int n)
{
    //递归
    if (index != n - 1)
        fun(index + 1, n);
    //归来处理
    cout << a[index];
}
int main()
{
    cin >> a;
    int a_len = a.size();
    int index = 0;
    fun(index, a_len);
    cout << endl;
    return 0;
}
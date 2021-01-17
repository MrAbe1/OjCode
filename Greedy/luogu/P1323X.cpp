#include <bits/stdc++.h>
using namespace std;
#define rec(i, a, b) for (int i = (a); i <= (b); ++i)
typedef long long ll;
const int inf = 0x3f3f3f3f;
const ll maxn = 1e5 + 10;
string s = "";
int a[maxn];
int m, k;
//不会
//计算出集合中的元素
void fun(int *a)
{
    a[1] = 1;
    rec(i, 2, 30001)
    {
        a[i] = a[i - 1] * 2 + 1;
    }
}
int main()
{
    cin >> k >> m;
    fun(a);
    rec(i, 1, k)
    {
        //把整数转成字符放到s中
        s += to_string(a[i]);
    }
    cout << s;
    s.push_back('9' + 1);
    int len_s = s.size();
    rec(i, 1, m)
    {
        int j;
        for (j = 0; j <= len_s - 1; j++)
        {
            if (s[j] < s[j + 1])
            {
                s.erase(j, 1);
                break;
            }
        }
    }
    s.pop_back();
    cout << s << endl;
    return 0;
}
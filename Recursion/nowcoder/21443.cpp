#include <bits/stdc++.h>
using namespace std;
#define rrec(i, a, b) for (int i = (a); i >= (b); i--)
#define rec(i, a, b) for (int i = (a); i <= (b); ++i)
typedef long long ll;
const int inf = 0x3f3f3f3f;
const ll maxn = 1e5 + 10;
int T;
string s;
string make()
{
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '4')
        {
            s.erase(i, 1);
            i--;
        }
    }
    if (s == "") //s.empty()
        return "YAMERO!";
    return s;
}
int main()
{
    cin >> T;
    while (T--)
    {
        cin >> s;
        cout << make() << endl;
    }
    system("pause");
    return 0;
}

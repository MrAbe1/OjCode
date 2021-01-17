#include <bits/stdc++.h>
using namespace std;
#define rrec(i, a, b) for (int i = (a); i >= (b); i--)
#define rec(i, a, b) for (int i = (a); i <= (b); ++i)
typedef long long ll;
const int inf = 0x3f3f3f3f;
const ll maxn = 1e5 + 10;
ll n;
ll ans = 0;
int t;
pair<int, int> pa;
//建立一个小根堆
priority_queue<ll, vector<ll>, greater<ll>> pq;
int main()
{
    cin >> n;
    rec(i, 1, n)
    {
        cin >> t;
        pq.push(t);
    }
    rec(i, 1, n - 1)
    {
        int a = pq.top();
        pq.pop();
        int b = pq.top();
        pq.pop();
        ans += (a + b);
        pq.push(a + b);
    }
    cout << ans << endl;
    system("pause");
    return 0;
}
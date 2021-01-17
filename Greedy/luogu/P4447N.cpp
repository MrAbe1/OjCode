#include <bits/stdc++.h>
using namespace std;
#define rrec(i, a, b) for (int i = (a); i >= (b); i--)
#define rec(i, a, b) for (int i = (a); i <= (b); ++i)
typedef long long ll;
const int inf = 0x3f3f3f3f;
const ll maxn = 1e5 + 10;
int temp;
int n;
//建立一个小顶堆
priority_queue<ll, vector<ll>, greater<ll>> pq[maxn];
ll a[maxn];
bool cmp(ll a, ll b)
{
    return a < b;
}
int main()
{

    cin >> n;
    rec(i, 1, n)
    {
        cin >> a[i];
    }
    sort(a + 1, a + 1 + n);
    int j = 0;
    rec(i, 1, n)
    {
        temp = j;
        if (pq[j].size() != 0)
        {
            ll top = pq[j].top();
            //pq[j].pop();
            if (a[i] == top + 1)
            {
                pq[j].push(a[i]);
                break;
            }
            else
            {
                for (; j >= 0; j--)
                {
                    if (a[i] == pq[j].top() + 1)
                    {
                        pq[j].push(a[i]);
                        break;
                    }
                }
                if (j == 0)
                {
                    j = temp + 1;
                    pq[j].push(a[i]);
                    break;
                }
            }
        }
        else
        {
            pq[j].push(a[i]);
            break;
        }
    }

    ll ans = inf;
    rec(m, 0, temp)
    {
        ans = ans > pq[m].size() ? pq[m].size() : ans;
    }
    cout << ans << endl;

    system("pause");
    return 0;
}
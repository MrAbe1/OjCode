#include <bits/stdc++.h>
using namespace std;
#define rec(i, a, b) for (int i = (a); i <= (b); i++)

typedef pair<int, int> pa;

const int maxn = 1e6 + 10;
int a[maxn];
int b[maxn];
//vs自动把> >变成>>,选取c++11即可

priority_queue<pa, vector<pa>, greater<pa>> pq;
int main()
{
    int n, m;
    cin >> n >> m;
    rec(i, 1, n)
    {
        cin >> a[i];
    }
    if (m >= n)
    {
        sort(a + 1, a + n + 1);
        cout << a[n];
        return 0;
    }
    rec(i, 1, m)
    {
        b[i] = a[i];
        pq.push(make_pair(a[i], i));
    }
    rec(i, m + 1, n)
    {
        pa temp = pq.top();
        pq.pop();
        temp.first += a[i];
        pq.push(temp);
    }
    int ans = 0;
    //获取优先队列的最大的一个
    while (!pq.empty())
    {
        pa temp = pq.top();
        if (ans < temp.first)
            ans = temp.first;
        pq.pop();
    }
    cout << ans << endl;
    return 0;
}
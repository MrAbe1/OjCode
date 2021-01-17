#include <bits/stdc++.h>
using namespace std;
int n;
int a[100001];
int ans = 0;
priority_queue<int, vector<int>, greater<int>> pq;
int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        pq.push(a[i]);
    }
    while (pq.size() != 1)
    {
        int a = pq.top();
        pq.pop();
        int b = pq.top();
        pq.pop();
        pq.push(a + b);
        ans += a * b;
    }
    cout << ans << endl;
    return 0;
}
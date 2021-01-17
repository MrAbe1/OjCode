#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int inf = 0x3f3f3f3f;
const ll maxn = 1e5 + 10;
int main()
{
    int N, K;
    cin >> N >> K;
    // int sum = K;
    // int cnt = 1;
    // int temp = K;
    // while (sum < N)
    // {
    //     temp *= K;
    //     sum += temp;
    //     cnt++;
    // }
    // cout << cnt << endl;

    //第二种 优化写法
    ll sum = 0;
    for (int i = 1, u = K;; i++, u *= K)
    {
        sum += u;
        if (sum >= N)
        {
            cout << i << endl;
            break;
        }
    }

    return 0;
}
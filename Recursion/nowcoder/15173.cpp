#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int inf = 0x3f3f3f3f;
const ll maxn = 1e5 + 10;
ll n;
ll cnt = 0;
ll caculate(ll n)
{
    ll sum = 0;
    while (n)
    {
        sum += n % 10;
        n /= 10;
    }
    return sum;
}
void fun(ll n)
{

    if (caculate(n) > 10)
    {
        fun(caculate(n));
    }
    else
    {

        cout << caculate(n) << endl;
    }
}

int main()
{
    cin >> n;
    fun(n);
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
#define rrec(i, a, b) for (int i = (a); i >= (b); i--)
#define rec(i, a, b) for (int i = (a); i <= (b); ++i)
typedef long long ll;
const int inf = 0x3f3f3f3f;
const ll maxn = 1e5 + 10;
int a, b;
const int mod = 9901;
//这题用到了约数和公式
/**
 * 证明：若n可以分解质因数：n=p1^a1*p2^a2*p3^a3*…*pk^ak,
可知p1^a1的约数有:p1^0, p1^1, p1^2......p1^a1
…
同理可知，pk^ak的约数有:pk^0, pk^1, pk^2......pk^ak ；
实际上n的约数是在p1^a1、p2^a2、...、pk^ak每一个的约数中分别挑一个相乘得来，
可知共有(a₁+1)(a₂+1)(a₃+1)…(ak+1)种挑法，即约数的个数。
由乘法原理可知它们的和为
f(n)=(p1^0+p1^1+p1^2+…p1^a1)(p2^0+p2^1+p2^2+…p2^a2)…(pk^0+pk^1+pk^2+…pk^ak）
——百度百科

y总
k为奇数时，可以分成等量的式子,注意k/2  == k-1/2
sum(p,k)= p^0+p^1+p^2+...+p^k
        = p^0+(p^1+...+p^k/2)+p^(k/2+1)+...+p^k
        =p^0+(p^1+...+p^k/2)+p^(k/2+1)+...+p^k
        =(P^0 +p^1+...+p^k/2)+p^(k/2+1)(p^0+...+p^k/2)
        =(1+p^(k/2+1))*sum(p,k/2)

k为偶数时
sum(p,k)= p^0+p^1+p^2+...+p^k
        = p^0+(p^1+...+p^k/2)+p^(k/2+1)+...+p^k
        =p^0+(p^1+...+p^k/2)+p^(k/2+1)+...+p^k
        =P^0 +(p^1+...+p^k/2)+p^(k/2)(p^1+...+p^k/2)
        =p^0+(1+p^k/2)(sum(p,k/2)-p^0)



*/
//快速幂
int qmi(int a, int b)
{
    //这一句一定要先加上
    a %= mod;

    int res = 1;
    while (b)
    {
        if (b & 1)
            res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}
//sum 计算
int sum(int a, int k)
{
    if (k == 0)
        return 1;
    //k为奇数时候
    if (k & 1)
        //return a % mod * (sum(a, k - 1) + 1) % mod;
        return (1 + qmi(a, k / 2 + 1)) * sum(a, k / 2) % mod;
    // return 1 + (1 + qmi(a, k / 2)) % mod * (sum(a, k / 2) - 1) % mod;
    //return (1 + qmi(a, k / 2 + 1)) * sum(a, k / 2) % mod;
    return (1 + a % mod * sum(a, k - 1)) % mod;
}
int main()
{

    cin >> a >> b;
    int res = 1;
    for (int i = 2; i <= a; i++)
    {
        int s = 0;
        while (a % i == 0)
        {
            s++;
            a /= i;
        }
        if (s)
            res = res % mod * (sum(i, s * b)) % mod;
    }
    //cout << qmi(a, b) << endl;
    //a等于0  特判
    if (!a)
        res = 0;
    cout << res << endl;
    system("pause");
    return 0;
}

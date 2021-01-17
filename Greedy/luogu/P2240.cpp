#include <bits/stdc++.h>
using namespace std;
#define rrec(i, a, b) for (int i = (a); i >= (b); i--)
#define rec(i, a, b) for (int i = (a); i <= (b); ++i)
typedef long long ll;
const int inf = 0x3f3f3f3f;
const ll maxn = 1e5 + 10;
int N, T;
int m[maxn];
int v[maxn];
double rate[maxn];
// bool cmp(double a, double b)
// {
//     return a > b;
// }
int main()
{
    cin >> N >> T;
    rec(i, 1, N)
    {
        cin >> m[i] >> v[i];
        rate[i] = v[i] / (m[i] * 1.0);
    }
    //从大到小排序
    //sort(rate + 1, rate + 1 + N, cmp);

    //手写一个冒泡排序，让mi，vi，ratei同时改变
    for (int i = 1; i <= N - 1; i++)
    {
        for (int j = 1; j <= N - i; j++)
        {
            if (rate[j] < rate[j + 1])
            {
                swap(rate[j], rate[j + 1]);
                swap(m[j], m[j + 1]);
                swap(v[j], v[j + 1]);
            }
        }
    }

    // rec(i, 1, N)
    // {
    //     cout << m[i] << " " << v[i] << " " << rate[i] << endl;
    // }

    double weight = 0;
    double value = 0;
    double left = T * 1.0;

    //这种是错误的写法，因为这个时候，rate i对应的就不是最原始的mi ,vi
    rec(i, 1, N)
    {
        //如果第i个物品的重量小于剩余的重量，直接装入
        if (m[i] < left)
        {
            weight += m[i] * 1.0;
            value += v[i] * 1.0;
            left -= m[i] * 1.0;
        }
        else //剩下的需要按照比例装入
        {
            value += rate[i] * left;
            weight = T * 1.0;
            left = 0;
            break;
        }
    }
    printf("%.2lf", value);
    system("pause");

    return 0;
}
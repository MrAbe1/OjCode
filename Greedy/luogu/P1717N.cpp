#include <bits/stdc++.h>
using namespace std;
#define rrec(i, a, b) for (int i = (a); i >= (b); i--)
#define rec(i, a, b) for (int i = (a); i <= (b); ++i)
typedef long long ll;
const int inf = 0x3f3f3f3f;
const ll maxn = 1e5 + 10;
int n, h;
int f[maxn], d[maxn], t[maxn];
//end 代表一直钓到哪个池塘，left代表剩余钓的次数
//返回可钓鱼的数目
int get_ans(int end, int left)
{

    //pq默认是大根堆，按照第一个元素进行排序
    //存放第i个池塘 可钓鱼的数量f[i];
    priority_queue<pair<int, int>> pq;
    rec(i, 1, end)
    {
        pq.push(make_pair(f[i], i));
    }
    int ret = 0;
    for (; left > 0; left--)
    {
        int val = pq.top().first;
        int i = pq.top().second;
        pq.pop();
        if (val <= 0)
            break;
        ret += val;
        pq.push(make_pair(val - d[i], i));
    }
    return ret;
}
int main()
{
    cin >> n >> h;
    //h代表行动的次数
    h = h * 60 / 5;
    rec(i, 1, n)
    {
        cin >> f[i];
    }
    rec(i, 1, n)
    {
        cin >> d[i];
    }
    rec(i, 2, n)
    {
        cin >> t[i];
    }
    int spend = 0;
    int ans = 0;
    //spend 为到i个池塘需要花费的时间
    //left为到i个池塘后剩余的可用于钓鱼的时间
    //ans 存放每次到第i个池塘最大可钓鱼的数目，和之前最大数目比较的返回的结果
    rec(i, 1, n)
    {
        spend += t[i];
        int left = h - spend;
        ans = max(ans, get_ans(i, left));
    }
    cout << ans << endl;
    system("pause");
    return 0;
}
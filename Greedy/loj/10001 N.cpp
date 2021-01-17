#include <bits/stdc++.h>
using namespace std;
#define rrec(i, a, b) for (int i = (a); i >= (b); i--)
#define rec(i, a, b) for (int i = (a); i <= (b); ++i)
typedef long long ll;
const int inf = 0x3f3f3f3f;
const int maxn = 3e4 + 10;
//这里不用pair是因为pair一次只能存储一对数字，所以用结构体进行
struct Node
{
    int b, e, t;
};
int n, h;
Node a[maxn];
//默认为0，所以shu数组没有进行初始赋值，但是我加了！！
int shu[maxn];
//排序，直接按照end排序,如果end相同，按照start排序
bool cmp(Node a, Node b)
{
    if (a.e == b.e)
        return a.b < b.b;
    return a.e < b.e;
}
//统计i到j区间有多少棵树
int get_sum(int i, int j)
{
    int sum = 0;
    rec(m, i, j)
    {
        if (shu[m] == 1)
        {
            sum++;
        }
    }
    return sum;
}
int main()
{

    cin >> n >> h;
    rec(i, 1, h)
    {
        cin >> a[i].b >> a[i].e >> a[i].t;
    }

    sort(a + 1, a + 1 + h, cmp);

    int cnt = 0;
    //对于每个区间进行种树
    rec(i, 1, h)
    {
        //获取当前区间有多少棵树
        int t2 = get_sum(a[i].b, a[i].e);
        //还需要种的数目
        int t = a[i].t - t2;
        if (t <= 0)
            continue;
        //从右边开始种树
        rrec(j, a[i].e, a[i].b)
        {
            if (shu[j] == 0)
            {
                shu[j] = 1;
                cnt++;
                t--;
            }
            if (t == 0)
                break;
        }
    }
    cout << cnt << endl;
    system("pause");
    return 0;
}

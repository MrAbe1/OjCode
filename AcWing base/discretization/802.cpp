#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef pair<int, int> PII;
const int N = 300010;
int n, m;
int a[N], s[N];
vector<int> alls;
vector<PII> add, query;
//把x映射到数组的下标
//这里二分处理的是从0开始的alls数组，所以l = 0, r = alls.size() - 1;，
//返回的r是从0开始的下标,而我们处理的a[]数组希望从1开始，
//所以为了方便后续前缀和求取区间和，所以末尾是r + 1
//找到从左开始第一个>=x的数字下标
int find(int x)
{
    int l = 0, r = alls.size() - 1;
    while (l < r)
    {
        int mid = l + r >> 1;
        if (alls[mid] >= x)
            r = mid;
        else
            l = mid + 1;
    }
    return r + 1;
}
/**
 * 在排完序的前提下，计算的不重复
 * 1.第一个元素
 * 2.当前元素与前一个不一样
 * 
 * vector<int>::iterator unique(vector<int> &a)
{
    int j = 0;
    for (int i = 0; i < a.size(); i ++ )
        if (!i || a[i] != a[i - 1])
            a[j ++ ] = a[i];
    // a[0] ~ a[j - 1] 所有a中不重复的数

    return a.begin() + j;
}
*/
int main()
{
    cin >> n >> m;
    //输入
    for (int i = 0; i < n; i++)
    {
        int x, c;
        cin >> x >> c;
        add.push_back({x, c});
        alls.push_back(x);
    }
    for (int i = 0; i < m; i++)
    {
        int l, r;
        cin >> l >> r;
        query.push_back(make_pair(l, r));
        alls.push_back(l);
        alls.push_back(r);
    }

    //去重比如001200003  得到0123，不去重当然也可以，比如0还是可以找到对应的a数组
    //但是方便了检索的效率
    sort(alls.begin(), alls.end());
    alls.erase(unique(alls.begin(), alls.end()), alls.end());

    //处理插入 找到原始的位置对应到新数组的位置，插值，
    //不去重的话也还是找到第一个对应的元素位置插
    for (auto item : add)
    {
        int x = find(item.first);
        a[x] += item.second;
    }
    //预处理前缀和下标从1开始不用管边界
    for (int i = 0; i <= alls.size(); i++)
        s[i] = s[i - 1] + a[i];
    //处理询问
    for (auto item : query)
    {
        int l = find(item.first), r = find(item.second);
        cout << s[r] - s[l - 1] << endl;
    }
}

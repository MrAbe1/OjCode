#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef pair<int, int> PII;
void merge(vector<PII> &segs)
{
    vector<PII> res;
    sort(segs.begin(), segs.end());
    //哨兵
    int st = -2e9, ed = -2e9;
    for (auto seg : segs)
    {
        //当前维护区间与遍历的区间没有交集，放入vector中，然后更新维护区间
        if (ed < seg.first)
        {
            //防止是第一个维护区间
            if (st != -2e9)
                res.push_back({st, ed});
            st = seg.first, ed = seg.second;
        }
        else
        {
            //把当前的区间拉长，暂时不需要加入res中
            ed = max(ed, seg.second);
        }
    }
    //加判断是防止segs初始为空，这里把最后一个区间加到结果里面
    //循环到了最后一个区间时候，只把上一个维护区间放到了res中，
    //只更新了区间，但是没有放进去a
    if (st != -2e9)
        res.push_back({st, ed});
    segs = res;
}
int main()
{
    int n;
    cin >> n;
    vector<PII> segs;
    for (int i = 0; i < n; i++)
    {
        int l, r;
        cin >> l >> r;
        segs.push_back({l, r});
    }
    merge(segs);
    cout << segs.size() << endl;
    return 0;
}
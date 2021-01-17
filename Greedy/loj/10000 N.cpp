#include <bits/stdc++.h>
using namespace std;

#define rrec(i, a, b) for (int i = (a); i >= (b); i--)
#define rec(i, a, b) for (int i = (a); i <= (b); ++i)
typedef long long ll;
const int inf = 0x3f3f3f3f;
const ll maxn = 1e5 + 10;
pair<int, int> pa;
vector<pair<int, int>> ht;
int main()
{

    int n;
    cin >> n;
    rec(i, 1, n)
    {
        int start, end;
        cin >> start >> end;
        ht.push_back(make_pair(end, start)); //vector下标从0开始0...n-1；
    }
    //按照结束时间从早到晚排列
    sort(ht.begin(), ht.end());
    int cnt = 1;
    int pre = 0;
    rec(i, 1, n - 1)
    {
        //i个活动的开始时间比前一个的结束时间要晚，结束时间也要满足这个条件，即不重复
        if (ht[i].second >= ht[pre].first && ht[i].first >= ht[pre].first)
        {
            cnt++;
            pre = i;
        }
    }
    cout << cnt << endl;
    //  system("pause");
    return 0;
}
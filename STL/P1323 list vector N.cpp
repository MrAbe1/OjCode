#include <bits/stdc++.h>
using namespace std;
typedef list<int>::iterator lit;
#define rec(i, a, b) for (int i = (a); i <= (b); ++i)
#define rrec(i, a, b) for (int i = (a); i >= (b); i--)
typedef long long ll;
vector<int> v;
list<int> l;
priority_queue<int, vector<int>, greater<int>> pq;
typedef list<int>::iterator LIT;
const int inf = 0x3f3f3f3f;
const ll maxn = 1e5 + 10;
int n, m;
int k;
LIT findFirst(LIT it)
{
    //找到第一个比后面元素小的数字返回
    while (1)
    {
        LIT now = it;
        it++;
        if (*now < *it)
            return now;
    }
}

int main()
{
    pq.push(1);
    rec(i, 1, 30000)
    {
        int a = pq.top() * 2 + 1;
        int b = pq.top() * 4 + 5;
        pq.push(a);
        pq.push(b);
        v.push_back(pq.top());
        pq.pop();
    }
    cin >> k >> m;
    rec(i, 0, k - 1)
    {
        cout << v[i];
        string s = to_string(v[i]);
        //字符串"123" 的第一个元素是'1'
        rec(j, 0, s.size() - 1)
        {
            //转换成int存储
            l.push_back(s[j] - '0');
        }
    }
    cout << endl;
    l.push_front(10);
    l.push_back(10);

    LIT b = l.begin();
    rec(i, 1, m)
    {
        b = findFirst(b);
        b = l.erase(b);
        b--;
    }
    l.pop_back();
    l.pop_front();
    if (l.size() == 0)
    {
        cout << 0;
    }
    else
    {
        for (LIT i = l.begin(); i != l.end(); i++)
        {
            cout << *i;
        }
    }

    return 0;
}
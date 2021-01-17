#include <iostream>
#include <set>
using namespace std;
const int N = 10010;
int height[N];
int main()
{
    int n, p, h, m;
    cin >> n >> p >> h >> m;
    set<pair<int, int>> existed;
    //最开始的height充当差分数组使用
    //无关p，因为p无论在什么位置，初始的差分数组height[p] = 0
    //默认都是h，在同一基准上面减
    height[1] = h;
    for (int i = 1, a, b; i <= m; i++)
    {
        cin >> a >> b;
        if (a > b)
            swap(a, b);
        if (!existed.count({a, b}))
        {
            existed.insert({a, b});
            //把a，b 之间的所有元素[a+1,b-1]都减掉1
            ////在区间[x,y]内的每个数加上k
            // a[x] += k, a[y + 1] -= k;
            height[a + 1]--;
            height[b]++;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        height[i] += height[i - 1];
        cout << height[i] << endl;
    }
    return 0;
}
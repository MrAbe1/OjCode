#include <iostream>
using namespace std;
const int N = 100010;
int a[N], s[N];
int n;
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    int res = 0;
    for (int i = 1, j = 1; i <= n; i++)
    {
        s[a[i]]++;
        //用while而不是if
        //每次添加一个a[i]的时候，s[a[i]]统计a[i]的个数
        //当s[a[i]]>1说明i，j之间有重复元素，这个时候j肯定要不断的前移
        //在前移的过程中把s[a[i]]给释放掉，用while而不是if
        //例子  1 2 2 2 3
        while (s[a[i]] > 1)
        {
            s[a[j]]--;
            j++;
        }
        res = max(res, i - j + 1);
    }
    cout << res << endl;
}
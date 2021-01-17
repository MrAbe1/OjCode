#include <iostream>
using namespace std;
const int N = 100010;
int a[N];
//数组从小到大排序
//二分 >= 从左到右找到第一个满足条件的值，可能是>也可能是=
//     <= 从左到右找到最后一个满足条件的值，可能是<也可能是=
//       (后面一个就不满足这个条件了>,因为从小到大的特性)
int main()
{
    int n, q;
    cin >> n >> q;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    while (q--)
    {
        int i;
        cin >> i;
        int l = 1, r = n;
        while (l < r)
        {
            int mid = l + r >> 1;
            if (a[mid] >= i)
                r = mid;
            else
            {
                l = mid + 1;
            }
        }
        if (a[l] != i)
            cout << "-1 -1" << endl;
        else
        {
            cout << l - 1 << ' ';
            l = 1, r = n;
            while (l < r)
            {
                int mid = l + r + 1 >> 1;
                if (a[mid] <= i)
                    l = mid;
                else
                {
                    r = mid - 1;
                }
            }
            cout << l - 1 << endl;
        }
    }
    return 0;
}
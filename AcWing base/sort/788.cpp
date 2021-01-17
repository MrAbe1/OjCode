#include <iostream>
using namespace std;
typedef long long ll;
const int N = 100010;
int a[N];
int tmp[N];
ll res = 0;
//本题相当于把逆序对的种类分成了三种，
//一种在左半边，一种在右半边，一种一个在左一个在右，
//分而治之的思想，分成两半，然后处理第三种情况
//当q[i]>q[j]说明后面的所有的元素都大于q[j]，mid-i+1
//然后不断的调整j的值，把大于特定q[j]的所有值加起来即为第三种情况

//这题数量级是10^5 所以nlogn的时间复杂度可以，n^2 快排的方式肯定不行
//然后逆序对的数目也是n^2级别，所以需要使用long long
ll merge_sort(int q[], int l, int r)
{
    if (l >= r)
        return 0;
    int mid = l + r >> 1;
    ll res = merge_sort(q, l, mid) + merge_sort(q, mid + 1, r);
    int i = l, j = mid + 1, k = 0;
    while (i <= mid && j <= r)
    {
        if (q[i] <= q[j])
        {
            tmp[k++] = q[i++];
        }
        else
        {
            res += mid - i + 1;
            tmp[k++] = q[j++];
        }
    }
    //扫尾，避免有的数没有放进数组里面
    while (i <= mid)
        tmp[k++] = q[i++];
    while (j <= r)
        tmp[k++] = q[j++];

    //物归原主
    for (int i = l, k = 0; i <= r; i++, k++)
        q[i] = tmp[k];
    return res;
}
int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    cout << merge_sort(a, 1, n) << endl;
    return 0;
}
#include <iostream>
using namespace std;
const int N = 100010;
int a[N];

void quick_sort(int q[], int l, int r)
{
    if (l >= r)
        return;
    int i = l - 1, j = r + 1, x = q[r + l >> 1];
    while (i < j)
    {
        do
            i++;
        while (q[i] < x);
        do
            j--;
        while (q[j] > x);
        if (i < j)
            swap(q[i], q[j]);
    }
    //这里用j而不是i，因为最后可能会出现j<i的情况，
    //好比[0,0] j=1 i=2
    //如果是(q,l,i),(q,i+1,r)的话，
    //那么区间就是[1, 2], [ 3, 2 ];
    // 意味着第一个区间进入了一种死循环的状态中
    quick_sort(q, l, j);
    quick_sort(q, j + 1, r);
}
int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    quick_sort(a, 0, n);
    for (int i = 1; i <= n; i++)
        cout << a[i] << ' ';
    cout << endl;
    return 0;
}
#include <iostream>
#include <iomanip>
#include <cmath>
#include <set>
using namespace std;
int tmp[100];
set<pair<int, int>> s;
void quick_sort(int q[], int l, int r)
{
    if (l >= r)
        return;
    int i = l - 1, j = r + 1, x = q[i + r >> 1];
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
    quick_sort(q, l, i);
    quick_sort(q, i + 1, r);
}

void merge_sort(int q[], int l, int r)
{
    if (l >= r)
        return;
    int mid = l + r >> 1;
    merge_sort(q, l, mid);
    merge_sort(q, mid + 1, r);
    int i = l, j = mid + 1, k = 0;
    while (i <= mid && j <= r)
    {
        if (q[i] < q[j])
            tmp[k++] = q[i++];
        else
        {
            tmp[k++] = q[j++];
        }
    }
    while (i <= mid)
        tmp[k++] = q[i++];
    while (j <= r)
        tmp[k++] = q[j++];
    for (int i = l, j = 0; i <= r; i++)
        q[i] = tmp[j++];
}
int main()
{
    int a[100];
    for (int i = 0; i < 10; i++)
    {
        a[i] = 10 - i;
        cout << a[i] << ' ';
    }
    merge_sort(a, 0, 9);
    for (int i = 0; i < 10; i++)
        cout << a[i] << ' ';

    // s.insert({1, 3});
    // s.insert({1, 3});
    // s.insert({1, 3});

    // s.insert({2, 3});
    // for (auto m : s)
    //     cout << m.first << " " << m.second << endl;

    return 0;
}
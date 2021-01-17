#include <iostream>
using namespace std;
const int N = 100010;
int a[N];
int tmp[N];
int n;
//segment Falut 之前数组开的不够大
void merge_sort(int q[], int l, int r)
{
    if (l >= r)
        return;
    int mid = l + r >> 1;
    merge_sort(q, l, mid);
    merge_sort(q, mid + 1, r);
    int i = l, j = mid + 1, k = 0;
    //等号！！判断条件不是i<j
    //归并排序是先平分有mid，最后从低往上，
    //快排是先随便取数，一般取中间x，先排，排完一个位置，再分，
    //所以递归的位置放置需要注意
    while (i <= mid && j <= r)
    {
        if (q[i] <= q[j])
            tmp[k++] = q[i++];
        else
            tmp[k++] = q[j++];
    }
    while (i <= mid)
        tmp[k++] = q[i++];
    while (j <= r)
        tmp[k++] = q[j++];
    for (int i = l, k = 0; i <= r; i++, k++)
        q[i] = tmp[k];
}
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &a[i]);
    }
    merge_sort(a, 1, n);
    for (int i = 1; i <= n; i++)
        printf("%d ", a[i]);
    return 0;
}
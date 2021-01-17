#include <iostream>
using namespace std;
const int N = 100010;
int a[N];
int diff[N];
int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++)
        diff[i] = a[i] - a[i - 1];
    while (m--)
    {
        int l, r, c;
        cin >> l >> r >> c;
        diff[l] += c;
        diff[r + 1] -= c;
    }
    //a[]为diff[]前缀和，所以，把diff[]相加更新之后得到新的a[]
    for (int i = 1; i <= n; i++)
        diff[i] += diff[i - 1];
    for (int i = 1; i <= n; i++)
        cout << diff[i] << " ";
    return 0;
}
/**
 * void insert(int l, int r, int c)
{
    b[l] += c;
    b[r + 1] -= c;
}
int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i ++ ) scanf("%d", &a[i]);

    for (int i = 1; i <= n; i ++ ) insert(i, i, a[i]);
…………
y总计算差分b[i]的方式
初始a[ ] 全为 0，b[ ]也全为0，即b初始就为a[ ]的前缀和，
把输入a[ i] 看成在[i,i]区间加上1，
那么对于差分数组b[ ]而言,就需要执行b[i]+=a[i],b[i+1]-=a[i]的操作了
惊艳！

*/
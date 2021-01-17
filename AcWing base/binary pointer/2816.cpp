#include <iostream>
const int N = 100010;
using namespace std;
int n, m;
int a[N], b[N];
int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < m; i++)
        cin >> b[i];
    int i = 0, j = 0;
    //判断a是否是b的子序列
    while (i < n && j < m)
    {
        if (a[i] == b[j])
            i++;
        j++;
    }
    if (i == n)
        puts("Yes");
    else
        puts("No");
    return 0;
}

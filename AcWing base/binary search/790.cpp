#include <iostream>
using namespace std;
const double eps = 1e-7;
int main()
{
    double n;
    cin >> n;
    double l = -25, r = 25;
    while (r - l > eps)
    {
        double mid = (l + r) / 2;
        if (mid * mid * mid >= n)
            r = mid;
        else
            l = mid;
    }
    //lf默认保留6位小数
    printf("%lf\n", l);

    return 0;
}
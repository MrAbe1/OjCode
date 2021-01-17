#include <iostream>
using namespace std;
const int N = 100010;
int a;
int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a;
        int res = 0;
        while (a)
        {
            if (a & 1)
                res++;
            a >>= 1;
        }
    }

    return 0;
}
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> div(vector<int> &A, int b, int &r)
{
    vector<int> c;
    r = 0;
    // a  “123456”
    // A [6 5 4 3 2 1]
    //一个数字一个数字拎出来处理，一开始的A的高位存放原数组的低位
    for (int i = A.size() - 1; i >= 0; i--)
    {
        r = r * 10 + A[i];
        //每次循环把商放到c中
        c.push_back(r / b);
        //把余数更新到r中
        r %= b;
    }
    //此时高位在c的低位,reverse之后，高位在c的高位即后面
    reverse(c.begin(), c.end());
    while (c.size() > 1 && c.back() == 0)
        c.pop_back();
    return c;
}
int main()
{
    string a;
    int b;
    cin >> a >> b;
    vector<int> A;

    for (int i = a.size() - 1; i >= 0; i--)
        A.push_back(a[i] - '0');
    int r;
    auto C = div(A, b, r);
    for (int i = C.size() - 1; i >= 0; i--)
        cout << C[i];
    cout << endl
         << r << endl;
    return 0;
}
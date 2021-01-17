#include <iostream>
#include <vector>
using namespace std;
// C = A * b, A >= 0, b > 0
vector<int> mul(vector<int> &A, int b)
{
    vector<int> c;
    int t = 0;
    for (int i = 0; i < A.size(); i++)
    {
        //t表示进位
        t += A[i] * b;
        c.push_back(t % 10);
        t /= 10;
    }
    while (t)
    {
        c.push_back(t % 10);
        t /= 10;
    }
    //可以整合到一块
    /**
 * for (int i = 0; i < A.size()||t; i++)
    {
        //t表示进位
        if(i<A.size())t += A[i] * b;
        c.push_back(t % 10);
        t /= 10;
    }
 
*/
    //去除开头多余的0
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
    auto c = mul(A, b);
    for (int i = c.size() - 1; i >= 0; i--)
        cout << c[i];
    return 0;
}
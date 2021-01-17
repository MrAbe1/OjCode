#include <iostream>
#include <vector>
using namespace std;
bool cmp(vector<int> &A, vector<int> &B)
{
    if (A.size() != B.size())
        return A.size() > B.size();
    else
    {
        for (int i = A.size() - 1; i >= 0; i--)
            if (A[i] != B[i])
                return A[i] > B[i];
    }
    return true;
}
vector<int> sub(vector<int> &A, vector<int> &B)
{
    vector<int> c;
    //t表示进位
    for (int i = 0, t = 0; i < A.size(); i++)
    {
        t = A[i] - t;
        if (i < B.size())
            t -= B[i];
        //这里的处理很巧妙
        //t表示A[i]-B[i]-t的结果，
        //如果这个结果小于0 表示需要借位+10，大于0不变
        //(t+10)%10刚好能表示这两种情况，取到个位放到c中
        c.push_back((t + 10) % 10);
        //表示需要借位
        if (t < 0)
            t = 1;
        else
            t = 0;
    }
    //去除数字开头多余的0
    while (c.size() > 1 && c.back() == 0)
        c.pop_back();
    return c;
}
int main()
{
    string a, b;
    vector<int> A, B;
    cin >> a >> b;
    for (int i = a.size() - 1; i >= 0; i--)
        A.push_back(a[i] - '0');
    for (int i = b.size() - 1; i >= 0; i--)
        B.push_back(b[i] - '0');

    if (cmp(A, B))
    {
        auto C = sub(A, B);
        for (int i = C.size() - 1; i >= 0; i--)
            cout << C[i];
        cout << endl;
    }
    else
    { //如果A<B ,用B-A 然后开头加负号
        auto C = sub(B, A);
        cout << '-';
        for (int i = C.size() - 1; i >= 0; i--)
            cout << C[i];
        cout << endl;
    }
    return 0;
}
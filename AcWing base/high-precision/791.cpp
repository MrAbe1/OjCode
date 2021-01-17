#include <iostream>
#include <vector>
using namespace std;
vector<int> add(vector<int> &A, vector<int> &B)
{
    vector<int> C;
    int t = 0;
    //另外一种
    /**
     * 
     * if(A.size()<B.size) return add(B,A);
     * 
     * for(int i=0;i<A.size();i++)
     * {
     *      t+=A.size();
     * if (i < B.size())    
     *    t += B[i];
     * ……
     * }
    */

    for (int i = 0; i < A.size() || i < B.size(); i++)
    {
        //把A[i] B[i]加起来存入t中
        if (i < A.size())
            t += A[i];
        if (i < B.size())
            t += B[i];
        //把余数依次放进c中
        C.push_back(t % 10);
        //此时t存储下一位的进位
        t /= 10;
    }
    //如果t有进位，加到后面
    if (t)
        C.push_back(t);
    return C;
}

int main()
{
    string a, b;
    cin >> a >> b;
    vector<int> A, B;
    //"123333"   ->  333321 A[0]存放低位 由低到高
    //把a,b字符串倒序转数字放到A，B中
    for (int i = a.size() - 1; i >= 0; i--)
        A.push_back(a[i] - '0');
    for (int i = b.size() - 1; i >= 0; i--)
        B.push_back(b[i] - '0');
    // auto c++11 特性 自动识别转换成类型本题相当于vector<int>
    auto c = add(A, B);
    for (int i = c.size() - 1; i >= 0; i--)
        cout << c[i];
    return 0;
}
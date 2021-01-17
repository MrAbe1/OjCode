#include <bits/stdc++.h>
using namespace std;
#define rec(i, a, b) for (int i = (a); i <= (b); ++i)
typedef long long ll;
const int inf = 0x3f3f3f3f;
const ll maxn = 1e5 + 10;
string N;
int k;
int main()
{
    cin >> N;
    cin >> k;
    int len_N = N.size();
    //确保最后一个元素也可以同样被删除掉
    //0比任意一个字符都小，所以即便到了末尾，那么说明最大的数在末尾需要删除掉
    N.push_back(0);
    rec(i, 1, k)
    {
        int j;
        for (j = 0; j <= len_N - 1; j++)
        {
            if (N[j] > N[j + 1])
            {
                break;
            }
        }
        N.erase(j, 1);
    }
    N.pop_back();
    //输出从第一个不为0的数输出
    bool flag = false;
    rec(i, 0, N.size() - 1)
    {
        if (N[i] != '0')
            flag = true;
        if (flag)
            cout << N[i];
    }
    if (flag)
        cout << endl;
    if (flag == false)
    {
        cout << "0" << endl;
    }
    return 0;
}

//        freopen("test.in","r",stdin);
//        freopen("test.out","w",stdout);

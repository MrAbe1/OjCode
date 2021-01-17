#include <bits/stdc++.h>
using namespace std;
string a;
bool isRepeat(string a)
{
    bool flag = false;
    int a_len = a.size();
    for (int i = 0; i < a_len; i++)
    {
        for (int j = i + 1; j < a_len; j++)
        {
            if (a[i] == a[j])
            {
                flag = true;
                break;
            }
        }
        if (flag)
            break;
    }
    return flag;
}
//剩下的不会了
int main()
{
    cin >> a;
    //getline(cin, a);
    cout << a;
    return 0;
}
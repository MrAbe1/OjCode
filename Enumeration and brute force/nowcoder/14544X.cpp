#include <bits/stdc++.h>
#include <string.h>
#include <cstring>
using namespace std;
//计算长度为8的回文数有多少

int main()
{
    bool flag = true;
    bool noneflag = false;
    int cnt = 0;
    string a = "10000000";
    while (a != "1000000000")
    {
        for (int i = 0; i < 4; i++)
        {
            if (a[i] != a[7 - i])
                flag = false;
        }
        if (flag)
        {

            cout << cnt << endl;
        }
        flag = true;
        a = to_string(stoi(a) + 1);
    }
    cout << cnt << endl;
    return 0;
}
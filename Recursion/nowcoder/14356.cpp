#include <bits/stdc++.h>
using namespace std;
//字符串  replace
int n;
string ans;
void change(int n)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < ans.length(); j++)
        {
            if (ans[j] == '0')
            {
                ans[j] = '1';
            }
            else if (ans[j] == '1')
            {
                //第j位置，1个元素 替换成为“01”
                ans.replace(j, 1, "01");
                j++;
            }
        }
    }
    cout << ans << endl;
}
int main()
{
    cin >> n;
    ans = "0";
    change(n);
    system("pause");
    return 0;
}
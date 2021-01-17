#include <bits/stdc++.h>
using namespace std;
#define rrec(i, a, b) for (int i = (a); i >= (b); i--)
#define rec(i, a, b) for (int i = (a); i <= (b); ++i)
typedef long long ll;
const int inf = 0x3f3f3f3f;
const ll maxn = 1e5 + 10;
int n;
int qipan[100][100] = {0};
int cnt = 0; //记录方案数

int showMap[100][100] = {0};

bool hang[100] = {0}; //标记第i行是否有queen
bool lie[100] = {0};  //标记第i列是否有queen
bool xie1[100] = {0}; //标记/是否有queen
bool xie2[100] = {0}; //标记\是否有queen

/**
 * 这里面的set 和 unset 对应之前的visited数组，如果被访问过那么不访问
*/

//放置queen 在（x,y)设置对应的标记
void set1(int x, int y)
{
    hang[x] = 1;
    lie[y] = 1;
    xie1[x + y] = 1;
    xie2[x - y + n] = 1;
}

//取消放置queen在（x，y)设置对应的标记
void un_set(int x, int y)
{
    hang[x] = 0;
    lie[y] = 0;
    xie1[x + y] = 0;
    xie2[x - y + n] = 0;
}

//坐标x，y能否放queen
bool is_right(int x, int y)
{
    if (hang[x] == 0 && lie[y] == 0 && xie1[x + y] == 0 && xie2[x - y + n] == 0)
        return true;
    return false;
}

//打印放置方案
void print_map()
{
    rec(i, 1, n)
    {
        rec(j, 1, n)
        {
            cout << showMap[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
    cout << endl;
    cout << endl;
}

void dfs(int x)
{
    if (x > n)
    {          //边界：来到n+1行，表示前n行都放好
        cnt++; //记录一次成功的方案
        cout << cnt << endl;
        print_map();
        return;
    }
    //i代表列
    rec(i, 1, n)
    {
        if (is_right(x, i))
        {
            set1(x, i);
            showMap[x][i] = 1;
            dfs(x + 1);
            un_set(x, i);
            showMap[x][i] = 0;
            //递归回来之后再恢复（1.递归完成输出，2、不合适，所以放在这里不影响）
        }
    }
}

int main()
{
    cin >> n;
    dfs(1);
    system("pause");
    return 0;
}

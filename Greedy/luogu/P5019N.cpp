#include <bits/stdc++.h>
using namespace std;
#define rrec(i, a, b) for (int i = (a); i >= (b); i--)
#define rec(i, a, b) for (int i = (a); i <= (b); ++i)
typedef long long ll;
const int inf = 0x3f3f3f3f;
const ll maxn = 1e5 + 10;
int n;
int d[maxn];
int main()
{
    ll ans = 0;
    cin >> n;
    rec(i, 1, n)
    {
        cin >> d[i];
    }
    rec(i, 2, n)
    {
        if (d[i] > d[i - 1])
        {
            ans += d[i] - d[i - 1];
        }
    }
    cout << ans + d[1] << endl;
    /*#include <bits/stdc++.h>
using namespace std;
const int maxn=1e5+10;
int ans=0,n,d[maxn];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&d[i]);
	d[0]=0;
	for(int i=1;i<=n;i++)               //这种在前面加d[0]的做法就很巧妙，据说差分
		if(d[i]>d[i-1]) 
			ans+=d[i]-d[i-1];	
	printf("%d",ans);
	return 0;
}

*/
    system("pause");
    return 0;
}

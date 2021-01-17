

/*第一种做法浪费内存，因为是递推，每次只和前两个元素有关，
  所以开两个空间足够了*/

//#include<bits/stdc++.h>
// using namespace std;
// const int MOD = 10007;
// const int N = 1e7+1;
// int f[N];
// int n;
// int Fibo(int n){
//     if(n==1 || n==2){
//         return 1;
//     }
//     f[1]=1;
//     f[2]=1;
//     for(int i =3; i<=n; i++){
//         f[i] = (f[i-1]+f[i-2])%MOD;
//     }
//     return f[n];
// }
// int main(){
//     cin>>n;
//     cout<<Fibo(n)<<endl;
//     return 0;
// }

#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e4 + 7;
int n;
int main()
{
    int f1 = 1;
    int f2 = 1;
    int f3;
    cin >> n;
    if (n == 1)
        cout << f1 << endl;
    if (n == 2)
        cout << f2 << endl;
    if (n >= 3)
    {
        for (int i = 3; i <= n; i++)
        {
            f3 = (f1 + f2) % MOD;
            f1 = f2 % MOD;
            f2 = f3 % MOD;
        }

        cout << f3 << endl;
    }

    return 0;
}
#include<iostream>
using namespace std;
const  int N=1000010;
int a[N];
int n,m;
int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    while(m--){
        int x;
        cin>>x;
        int l=1,r=n;
        while(l<r){
            int mid  = l+r>>1;
            if(a[mid]>=x) r=mid;
            else l=mid+1;
        }
        if(a[l]==x) cout<<l<<' ';
        else cout<<"-1"<<' ';
    }
    return 0;
}
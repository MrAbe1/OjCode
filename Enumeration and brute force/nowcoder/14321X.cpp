#include<bits/stdc++.h>
using namespace std;
int T;
int a,b;
long long int i = 1;

int main(){
    cin>>T;
    while(T--){
        cin>>a>>b;
        if(a+b>=(i<<32)){
            cout<<"NO"<<endl;
        }
        else{
            cout<<"YES"<<endl;
        }
        
    }
    return 0;
}
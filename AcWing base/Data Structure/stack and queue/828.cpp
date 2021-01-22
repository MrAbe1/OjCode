#include<iostream>
using namespace std;
const  int N=100010;
int sta[N],tt;
int main(){
    int m;
    cin>>m;
    while(m--){
        string op;
        int x;
        cin>>op;
        if(op=="push")
        {
            cin>>x;
            sta[++tt] =x;
        }else if(op=="pop"){
            tt--;

        }else if(op=="query"){
            cout<<sta[tt]<<endl;
        }else if(op=="empty"){
            if(tt>0)
            cout<<"NO"<<endl;
            else
            cout<<"YES"<<endl;
        }
    }
    return 0;
}
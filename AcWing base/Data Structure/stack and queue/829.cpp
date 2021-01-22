#include<iostream>
using namespace std;
const int N=100010;
//hh 头 tt尾 初始为-1 ，也可设为0；
int q[N],hh,tt=-1;
int main(){
    int m;
    cin>>m;
    while(m--){
        string op;
        int x;
        cin>>op;
        if(op=="push"){
          cin>>x;
            q[++tt]=x;
        }else if(op=="pop")
        {
            //注意是++
            ++hh;
        }else if(op=="empty")
        {
            cout<<(hh<=tt?"NO":"YES")<<endl;

        }else if(op=="query"){
            cout<<q[hh]<<endl;
        }
    }
            return 0;

}
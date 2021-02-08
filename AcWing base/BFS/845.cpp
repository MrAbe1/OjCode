#include<iostream>
#include<queue>
#include<unordered_map>
#include<cstring>
#include<algorithm>
using namespace std;
//bfs 的思路先把所有的东西放进队列，然后一个一个拿出来处理
int bfs(string start){
    queue<string> q;
    //hash 记录变成目标string 需要的步数
    unordered_map<string,int> d;
    //固定套路 先压起点
    q.push(start);
    d[start] = 0;
    
    int dx[]={-1,0,1,0},dy[]={0,1,0,-1};
    string end = "12345678x";
    while(q.size()){
        auto t = q.front();
        q.pop();
        if(t==end) return d[t];
        
        int distance = d[t];
        //坐标转换
        int k =t.find('x');
        int x = k/3,y = k%3;
        for(int i=0;i<4;i++)
        {
            int a= x+dx[i],b=y+dy[i];
            if(a>=0&&a<3&&b>=0&&b<3){
                //上右左下 顺序
                //如果当前状态没有访问过，入队
                swap(t[k],t[3*a+b]);
                if(!d.count(t)){
                    q.push(t);
                    d[t] = distance +1;
                }
                //当前状态入队结束之后。
                //需要重新修改回原有的状态，让别的状态入队。
                swap(t[k],t[3*a+b]);
            }
        }
    }
    return -1;
}
int main(){
    string st;
    for(int i=0;i<9;i++) {
        char t;
        cin>>t;
        st+=t;
    }
    cout<<bfs(st)<<endl;
    return 0;
}


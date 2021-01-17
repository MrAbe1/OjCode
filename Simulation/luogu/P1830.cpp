#include<bits/stdc++.h>
using namespace std;
int n,m,x,y;
int x1,x2,y3,y2;
int yx,yy; 
int times[101][101];
int lun[101][101];
int main(){
	cin>>n>>m>>x>>y;
	memset(lun,0,sizeof(lun));
	memset(times,0,sizeof(times));
	int roundIndex = 1;
	while(x--){
		cin>>x1>>y3>>x2>>y2;
		for(int i=x1;i<=x2;i++){
			for(int j=y3;j<=y2;j++){
				times[i][j]++;
				lun[i][j] = roundIndex;	
			}
		}
		roundIndex++;
	}
	while(y--){
		cin>>yx>>yy;
		if(times[yx][yy] == 0){
			cout<<"N"<<endl;
		}else{
			cout<<"Y "<<times[yx][yy]<<" "<<lun[yx][yy]<<endl; 
		}
	}
	return 0;
}

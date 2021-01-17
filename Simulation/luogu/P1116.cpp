#include<bits/stdc++.h>
using namespace std;
int N;
int a[10001];
int fun(int *a,int n){
	//ц╟ещеепР
	int cnt = 0;
	int temp;
	for(int i = 0; i< n-1 ;i++){
		for(int j = 0; j< n-1-i ;j++){
			if(a[j]>a[j+1]){
				temp = a[j];
				a[j]=a[j+1];
				a[j+1]= temp; 
				cnt++;
			}
		}
	} 
	return cnt;
}
int main(){
	cin>>N;
	int  i;
	for(i=0;i<N;i++){
		cin>>a[i];
	}
	cout<<fun(a,N)<<endl;
	return 0;
}


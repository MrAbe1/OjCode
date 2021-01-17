#include<bits/stdc++.h>
using namespace std;
int M;
char N[1001]; 
int N_No0_index[1001];
int main(){
	scanf("%d %s",&M,N);
	int index =0;
	int str_N = strlen(N); 
	for(int i=0;i<str_N;i++){
		if(N[str_N-1-i]!='0'){
			N_No0_index[index++]=str_N-1-i;
		}
	}
//	
//	for(int j=0;j<index;j++){
//		cout<<N_No0_index[j]<<" ";
//	}
	
	for(int j=0;j<index-1;j++){
		cout<<N[N_No0_index[index-1-j]]<<"*"<<M<<"^"<<N_No0_index[j]<<"+";
	}	
		cout<<N[N_No0_index[0]]<<"*"<<M<<"^"<<N_No0_index[index-1]<<endl;
	return 0;
}


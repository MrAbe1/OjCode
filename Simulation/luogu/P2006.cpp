//������Ŀ�ܴ�������a[i]>=1����Ȼ��a[i]==0�Ĳ��Ե�
//���ⲻ�����򣬿϶��Ǵ�С������ 
#include<bits/stdc++.h>
using namespace std;
const int N = 3e4+5;
int k,m,n;
int tempIndex;
int a[N],b[N];
int temp[N];
//��С�������� 
//void paixu(int *temp,int n) {
//	for(int i=0; i<n-1; i++) {
//		for(int j=0;j<n-1-i;j++){
//			if(a[j]>a[j+1]){
//				int tem = a[j];
//				a[j] = a[j+1];
//				a[j+1]=tem;
//			}
//		}
//	}
//}
 
int main() {
	cin>>k>>m>>n;
	memset(temp,0,sizeof(temp));
	tempIndex = 0;
	for(int i=0; i<m; i++) {
		cin>>a[i]>>b[i];
		if(a[i]!=0 && k/a[i]*b[i]>=n && a[i]<=k) {
			temp[tempIndex++]=i+1;
		}
		if(a[i]==0){
		temp[tempIndex++]=i+1;
		}
	}
//	paixu(temp,tempIndex);
	if(temp[0]==0){
			cout<<"-1"<<endl ;
	}else{
		for(int i=0;i<tempIndex-1;i++)
			cout<<temp[i]<<" ";
		cout<<temp[tempIndex-1]<<endl;
	}
	return 0;
}


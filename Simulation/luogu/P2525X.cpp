#include<bits/stdc++.h>
using namespace std;
int N;
int a[10];
bool flag = 1;
int main() {
	cin>>N;
	int ex;
	for(int i=0; i<N; i++)
		cin>>a[i];
	for(int j = N-1; j>=1; j--) {
		if(a[j-1] > a[j]) {
			ex = a[j];
			a[j] = a[j-1];
			a[j-1] = ex;
			flag=0;
			break;
		}
	}
	if(flag) {
		cout<<"ERROR"<<endl;
	} else {
		for(int i=0; i<=N-2; i++)
			cout<<a[i]<<" ";
		cout<<a[N-1]<<endl;
	}

	return 0;
}


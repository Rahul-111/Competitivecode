#include<bits/stdc++.h>
using namespace std;
void lexicographicalOrder(long long v,int n){
	if(v > n)	return;
	int upper=(v==1 ?9:10);
	for(int i=0;i<upper && v<=n;i++){
		cout<<v<<endl;
		lexicographicalOrder(v*10,n);
		++v;
	}
}
int main(){
	cout<<"Lexicographical Order "<<endl;
	int n;
	cin>>n;
	lexicographicalOrder(1,n);
	return 0;
}

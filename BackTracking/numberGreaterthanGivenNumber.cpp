//combination of given number greater than given number with duplicate
#include<iostream>
using namespace std;
int num(int *input,int *freq,int *fact,int n){
	if(n==0 || n==1)
		return 0;
	int ans=0;
	for(int i=input[0]+1;i<10;i++){
		if(freq[i] > 0){
			ans+=fact[n-1];
		}
	}
	freq[input[0]]--;
	ans += num(input+1,freq,fact,n-1);
	return ans;
}
int main(){
	int n;
	cin>>n;
	int input[n],fact[n+1],freq[10]={0};
	fact[0]=1;
	for(int i=0;i<n;i++){
		cin>>input[i];
		fact[i+1]=(i+1)*fact[i];
		freq[input[i]]++;
	}
	cout<<num(input,freq,fact,n);
}

#include<iostream>
using namespace std;
int alphaCodeRecursion(int *arr,int size){
	if(size==1)
		return 1;
	if(size==0)
		return 1;
	int output = alphaCodeRecursion(arr,size-1);
	if( arr[size-2]*10 + arr[size-1] <=26)
		output+=alphaCodeRecursion(arr,size-2);
	return output;
}
int alphaCodeRecursion2(int *arr,int size,int *output){
	if(size==1)
		return 1;
	if(size==0)
		return 1;
	if(output[size]>0)
		return output[size];
	int ans = alphaCodeRecursion2(arr,size-1,output);
	if( arr[size-1] + arr[size-2]*10 <= 26){
		ans += alphaCodeRecursion2(arr,size-2,output);
	}
	output[size]=ans;
	return output[size];
}
int alphaCodeDp(int *input,int n){
	int output[n+1]={0};
	output[0]=1;
	output[1]=1;
	for(int i=2;i<=n;i++){
		output[i]=output[i-1];
		if(output[i-2]*10+output[i-1] <= 26)
			output[i]+=output[i-2];
	}
	return output[n];
}
int main(){
	int n;
	cin>>n;
	int input[n];
	for(int i=0;i<n;i++)
		cin>>input[i];
	cout<<alphaCodeRecursion(input,n)<<endl;
	int output[n+1]={0};
	cout<<alphaCodeRecursion2(input,n,output)<<endl;
	cout<<alphaCodeDp(input,n)<<endl;
	return 0;
}

#include<iostream>
using namespace std;
void slidingWindowSum(int A[],int k,int n){
	int sum=0;
	for(int i=0;i<k;i++)
		sum+=A[i];
	cout<<sum<<" ";
	for(int i=1;i<n-k+1;i++){
		sum+=A[k+i-1]-A[i-1];
		cout<<sum<<" ";
	}
}
int main(){
	int A[]={1,3,2,1,4,1,3,2,1,1,2};
	int n=sizeof(A)/sizeof(A[0]);
	int windowsize=3;
	slidingWindowSum(A,windowsize,n);
	return 0;
}

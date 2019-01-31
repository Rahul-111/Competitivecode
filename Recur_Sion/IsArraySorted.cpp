#include<iostream>
using namespace std;
bool is_sorted(int arr[],int n){
	if(n==0 || n==1)
		return true;
	if(arr[0] > arr[1])
		return false;
	//return is_sorted(arr+1,n-1);
	bool isSmallerSorted=is_sorted(arr+1,n-1);
	return isSmallerSorted;
}
bool Is_sorted(int arr[],int n){
	if(n==0 || n==1)
		return true;
	bool isSmallerOutput=Is_sorted(arr+1,n-1);
	if(!isSmallerOutput)
		return false;
	if(arr[0] > arr[1])
		return false;
	else
		return true;
}
int main(){
	int arr[]={2,4,5,6,7};
	cout<<is_sorted(arr,sizeof(arr)/sizeof(arr[0]))<<endl;
	cout<<Is_sorted(arr,sizeof(arr)/sizeof(arr[0]))<<endl;
	return 0;
}

#include<iostream>

using namespace std;

//Iterative method
int Binary(int A[],int n,int x)
{
	int low=0,mid;
	int high=n-1;
	while(low<=high)
	{
		mid = low +(high-low)/2;
		
		if(x==A[mid])
			return mid;
		else if(x<A[mid])
		{
			high=mid-1;
		}
		else{
			low=mid+1;
		}
	}
	return -1;
}
//Recursive method
int Binary(int A[],int low,int high,int x)
{
	if(low>high) return -1;
	
	int mid=low+(high-low)/2;
	
	if(x==A[mid])
		return mid;
	else if(x<A[mid])
		return Binary(A,low,mid-1,x);
	else
		return Binary(A,mid+1,high,x);
}
int main()
{
	int arr[]={1,2,3,4,5,6,7,8,9};
	int n=sizeof(arr)/sizeof(arr[0]);
	//int flag=Binary(arr,n,2);
	int flag=Binary(arr,0,n-1,5);
	if(flag==-1)
	{
		cout<<"Match NOT FOUND";
	}
	else{
		cout<<"Match FOUND AT "<<flag+1;
	}
}

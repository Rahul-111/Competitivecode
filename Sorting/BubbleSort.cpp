#include<iostream>

using namespace std;


void BubbleSortImprove(int A[],int n)
{
	for(int i=0;i<n;i++)
	{	
		cout<<"he";
		int flag=0;
		for(int j=0;j<n-i-1;j++)
		{
			if(A[j]>A[j+1])
			{
				swap(A[j],A[j+1]);
				flag=1;
			}	
		}
		if(flag==0) break;
	}
}
void BubbleSort(int A[],int n)
{
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n-i-1;j++)
		{
			if(A[j]>A[j+1])
				swap(A[j],A[j+1]);
		}
	}
}

int main()
{
	int arr[]={2,1,4,3,9,6,8,7};
	int n=sizeof(arr)/sizeof(arr[0]);
	//BubbleSort(arr,n);
	BubbleSortImprove(arr,n);  //if there is sorted array
	for(int i=0;i<n;i++) cout<<arr[i]<<"  ";
}

#include<iostream>
#include<algorithm>
using namespace std;
int Partition(int arr1[],int start,int end)
{
	int value = arr1[end];
	int pIndex=start;
	for(int i=start;i<end;i++)
	{
		if(arr1[i]<=value)
		{
			swap(arr1[i],arr1[pIndex]);
			pIndex++;	
		}		
	}
	swap(arr1[pIndex],arr1[end]);
	return pIndex;
}
void quickSort(int arr1[],int start,int end)
{	
	if(start>=end)
	{
		return ;
	}
	int pIndex=Partition(arr1,start,end);
	quickSort(arr1,start,pIndex-1);
	quickSort(arr1,pIndex+1,end);
}
int binarySearch(int arr1[],int start,int end,int value)
{
	if(start <=end)
	{
		int mid=(start+end)/2;
	
		if(arr1[mid] == value)
			return mid;
		else if(value > arr1[mid])
		{
			return binarySearch(arr1,mid+1,end,value);
		}
		else if(value < arr1[mid])
		{
			return binarySearch(arr1,start,mid,value);
		}
	}
	return -1;
}
bool isSubset(int arr1[],int arr2[],int m,int n)
{
	quickSort(arr1,0,m-1);
	for(int i=0;i<m;i++)
	{
		if(binarySearch(arr1,0,m-1,arr2[i]) == -1)
			return false;
	}
	return true;
}
int main()
{
	int arr1[]={11,1,13,21,3,7};
	int arr2[]={11,1,3,7};
	
	int m=sizeof(arr1)/sizeof(arr1[0]);
	int n=sizeof(arr2)/sizeof(arr2[0]);
	
	if(isSubset(arr1,arr2,m,n)) cout<<"arr2[] is a subset of arr1[]";
	else cout<<"arr2[] is not a subset of arr1[]";
	return 0;
}

#include<iostream>
#include<cmath>
using namespace std;
int Max_SubArray(int A[],int n)
{
	int ans=INT_MIN;
	for(int sub_array_size = 1;sub_array_size <= n; ++sub_array_size)
	{
		for(int start_index = 0;start_index < n; ++start_index)
		{
			if(start_index+sub_array_size > n)
				break;
			int sum=0;
			for(int i=start_index;i<(start_index+sub_array_size);i++)
				sum+=A[i];
			ans = max(sum,ans);
		}
	}
	return ans;
}
int main()
{
	int arr[17]={100,113,110,85,105,102,86,63,81,101,94,106,101,79,94,90,97};
	int n=sizeof(arr)/sizeof(arr[0]);
	int arr2[16], j;
	//for(int i=0;i<n;i++) cout<<arr[i]<<"\t";
	for(int i=1;i<n;i++)
	{
		arr2[j]=arr[i]-arr[i-1];
		j++;
	}
	for(int j=0;j<n-1;j++) cout<<arr2[j]<<"\t";
	
	cout<<"ans= "<<Max_SubArray(arr2,n-1);
}


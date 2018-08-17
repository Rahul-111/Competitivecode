#include<iostream>
//#include<limit.h>
#include<bits/stdc++.h>
using namespace std;

int Max_SubArray(int arr[],int n)	
{
	if(n==1)
	{
		return arr[0];
	}
	int m = n/2;
	int left_MSS = Max_SubArray(arr,m);
	int right_MSS = Max_SubArray(arr+m,n-m);
	int leftsum = INT_MIN, rightsum = INT_MIN, sum=0;
	for(int i=m;i < n; i++)
	{
		sum += arr[i];
		rightsum = max(rightsum,sum);
	}
	sum = 0;
	for(int i= (m-1);i >= 0; i--)
	{
		sum += arr[i];
		leftsum = max(leftsum,sum);
	}
	int ans = max(left_MSS,right_MSS);
	return max(ans,leftsum+rightsum);
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
	//Max_SubArray(arr2,n-1);
	
	int ans =Max_SubArray(arr2,n-1);
	//x,y,z=Find_Max_SubArray(arr,0,n-1);
	cout<<"ans = "<<ans;
	return 0;
}

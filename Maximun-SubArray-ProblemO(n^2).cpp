#include<iostream>

using namespace std;
void Max_SubArray(int A[],int n)
{
	int left=0,right=0;
	int max=A[0];
	for(int i=0;i<n;i++)
	{
		int cumSum=0;
		for(int j=i;j<n;j++)
		{
			cumSum = cumSum+A[j];
			if(cumSum>max)
			{
				max = cumSum;
				left=i;
				right =j;
				//cout<<"\n Max = "<<cumSum<<"left "<<left<<" right"<<right;	
			}	
		}	
	}	
	cout<<"\nSum = "<<max<<" Between "<<left+1<<"  "<<right+1;
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
	
	Max_SubArray(arr2,n-1);
	
	return 0;
}

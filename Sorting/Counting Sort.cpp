#include<iostream>

using namespace std;
void countingSort(int A[],int B[],int n,int k)
{
	int C[k];
	for(int i=0;i<=k;i++)  C[i]=0;
	
	for(int j=0;j<n;j++)
		C[A[j]] = C[A[j]] + 1; //C[i] counts the number of elemnts equal to 1
	//for(int i = 0;i<=k;i++) cout<<C[i]<<"  ";
	for(int i=0;i<=k;i++)
		C[i] = C[i] + C[i-1];
	//for(int i = 0;i<=k;i++) cout<<C[i]<<"  ";
	cout<<"\n";
	for(int j=n-1; j>=0 ;j--)
	{
		B[C[A[j]]-1] = A[j];
		C[A[j]] = C[A[j]]-1; 
	}
}
int main()
{
	int arr[]={2,5,3,0,2,3,0,3};
	int n=sizeof(arr)/sizeof(arr[0]);
	
	for(int i=0;i<n;i++) cout<<arr[i]<<"  ";
	int B[n];
	countingSort(arr,B,n,5);
	cout<<"After Sorting :";
	for(int i=0;i<n;i++) cout<<B[i]<<"  ";
	return 0;
}

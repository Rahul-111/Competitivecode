#include<iostream>

using namespace std;

void Min_Heapify(int A[],int i,int n)
{
	int l=2*i+1;
	int r=2*i+2;
	int smallest = i;
	
	if(l < n && A[l] < A[smallest])
		smallest=l;
	if(r < n && A[r] < A[smallest])
		smallest=r;
	if(smallest != i)
	{
		swap(A[i],A[smallest]);
		Min_Heapify(A,smallest,n);
	}
}
void Build_Min_heap(int A[],int n)
{
	for(int i=n/2;i>=0;i--)
	{
		Min_Heapify(A,i,n);
	}
}
int main()
{
	int Arr[]={16,4,10,14,7,9,3,2,8,1};
	int n=sizeof(Arr)/sizeof(Arr[0]);
	//Min_Heapify(Arr,2,n);
	//heapify(Arr,n,1);
	Build_Min_heap(Arr,n);
	for(int i=0;i<n;i++) cout<<Arr[i]<<"  ";
	return 0;
}

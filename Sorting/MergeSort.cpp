#include<iostream>

using namespace std;
void Merge(int A[],int L[],int R[],int n1,int n2)
{
	int i=0,j=0,k=0;
	
	while(i<n1 && j<n2)
	{
		if(L[i]<R[j])
			A[k++]=L[i++];
		else
			A[k++]=R[j++];
	}
	while(i<n1){
		A[k++]=L[i++];
	}
	while(j<n2){
		A[k++]=R[j++];
	}
}

void MergeSort(int A[],int n)
{	
	int mid=n/2,*L,*R;
	if(n<2)
		return ;
	L=new int[mid];
	R=new int[n-mid];
	
	for(int i=0;i<mid;i++) L[i]=A[i];
	for(int i=mid;i<n;i++) R[i-mid]=A[i];
	MergeSort(L,mid);
	MergeSort(R,n-mid);
	Merge(A,L,R,mid,n-mid);
}
int main()
{
	int A[]={2,5,1,3,9,8,7};
	int n=sizeof(A)/sizeof(A[0]);
	MergeSort(A,n);
	for(int i=0;i<n;i++)
	{
		cout<<A[i]<<"\t";
	}
}

#include<iostream>
using namespace std;
void Merge(int A[],int l[],int r[],int n,int m){
	int i,j,k;
	i=j=k=0;
	while(i<n && j<m){
		if(l[i]<r[j]){
			A[k]=l[i];
			i++;
			k++;
		}
		else{
			A[k]=r[j];
			k++;
			j++;
		}
	}
	while(i<n){
		A[k]=l[i];
		i++;k++;
	}
	while(j<m){
		A[k]=r[j];
		k++;
		j++;
	}
}
void MergeSort(int A[],int n){
	if(n<2)
		return ;
	int mid=n/2;
	int *l=new int[mid];
	int *r=new int[n-mid];
	for(int i=0;i<mid;i++)
		l[i]=A[i];
	for(int i=mid;i<n;i++)
		r[i-mid]=A[i];	
	MergeSort(l,mid);
	MergeSort(r,n-mid);
	Merge(A,l,r,mid,n-mid);
} 
//void MergeB(int B[],int l[],int r[],int n,int m){
//	int i,j,k;
//	i=j=k=0;
//	while(i<n && j<m){
//		if(l[i]>r[j]){
//			B[k++]=r[j++];
//		}
//		else
//			B[k++]=l[i++];
//	}
//	while(i<n)
//		B[k++]=l[i++];
//	while(j<m)
//		B[k++]=r[j++];
//}
//void MergeSorT(int B[],int start,int end){
//	if(start>=end){
//		return;
//	}
//	int mid=(start+end)/2;
//	int *l=new int[mid+1];
//	int *r=new int[end-mid];
//	
//	for(int i=0;i<=mid;i++)
//		l[i]=B[i];
//	for(int j=mid+1;j<=end;j++)
//		r[j-mid-1]=B[j];
//	MergeSorT(l,start,mid);
//	MergeSorT(r,mid+1,end);
//	MergeB(B,l,r,mid+1,end-mid);
//}
int main(){
	int A[]={10,5,4,1,9,8};
	int n=sizeof(A)/sizeof(A[0]);
	MergeSort(A,n);
	for(int i=0;i<n;i++)
		cout<<A[i]<<" ";
	return 0;
}

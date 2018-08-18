#include<iostream>

using namespace std;

void Max_Heapify(int A[],int i,int n)
{
	int l = 2*i+1;
	int r = 2*i+2;
	int largest=i;
	if(l < n && A[l]> A[largest])
			largest=l;
	if(r < n && A[r] > A[largest])
			largest = r;
	if (largest != i)
	{
		swap(A[i],A[largest]);
		Max_Heapify(A,largest,n);	
	}
}

void Build_Max_heap(int A[],int n)
{
	for(int i=n/2;i>=0;i--)
	{
		Max_Heapify(A,i,n);
	}
}
int Heap_Max(int A[])
{
	return A[0];
}
int Heap_Extract_Max(int A[],int n)
{
	if(n<0)
	{
		cout<<"Heap Underflow";
	}
	int max = A[0];
	A[0] = A[n-1];
	n--;
	Max_Heapify(A,0,n);
	return max;
}
void Heap_Increase_key(int A[],int i,int key)
{
	if(key < A[i])
		cout<<"New key is smaller then current key";
	A[i] = key;
	int parent = (i-1)/2;
	while(i>0 && A[parent] < A[i])
	{
		swap(A[i],A[parent]);
		i=parent;
		parent = (i-1)/2;
	}
}
void Max_Heap_Insert(int A[],int key,int n)
{
	n++;
	A[n-1]=INT_MIN;
	Heap_Increase_key(A,n-1,key);
}
int main()
{
	int Arr[]={4,1,3,2,16,9,10,14,8,7};
	int n=sizeof(Arr)/sizeof(Arr[0]);
	
	Build_Max_heap(Arr,n);
	for(int i=0;i<n;i++) cout<<Arr[i]<<"  ";
	//cout<<"Heap-Maximum = "<<Heap_Max(Arr);
	
	//cout<<"Heap-Maximum = "<<Heap_Extract_Max(Arr,n)<<"\n";
	//cout<<"Heap :";
	//for(int i=0;i<n-1;i++) cout<<Arr[i]<<" ";
	//Heap_Increase_key(Arr,8,15);
	//cout<<"After Heap_Increase_key :";
	//for(int i=0;i<n;i++) cout<<Arr[i]<<"  ";
	Max_Heap_Insert(Arr,11,n);
	cout<<"\n After Insertion of a new node 11 \n";
	for(int i=0;i<n+1;i++) cout<<Arr[i]<<"  ";
	return 0;
}

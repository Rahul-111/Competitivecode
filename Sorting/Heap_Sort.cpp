#include<iostream>
#include<algorithm>
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
void heapify(int arr[], int n, int i)
{
    int largest = i;  // Initialize largest as root
    int l = 2*i + 1;  // left = 2*i + 1
    int r = 2*i + 2;  // right = 2*i + 2
 
    // If left child is larger than root
    if (l < n && arr[l] > arr[largest])
        largest = l;
 
    // If right child is larger than largest so far
    if (r < n && arr[r] > arr[largest])
        largest = r;
 
    // If largest is not root
    if (largest != i)
    {
        swap(arr[i], arr[largest]);
 
        // Recursively heapify the affected sub-tree
        heapify(arr, n, largest);
    }
}
// Ierative approach
int *Max_Heapify2(int A[],int i,int n)
{
	while(i<n)
	{
		int l =2*i+1;
		int r =2*i+2;
		int largest;
		if (l < n && A[l] > A[i])
        	largest = l;
        else
        	largest = i;
		if (r < n && A[r] > A[largest])
        	largest = r;
		        
        if (largest != i)
    	{
        	swap(A[i], A[largest]);
        	i=largest;
    	}
    	else{
    		return A;
		}
	}
	return A ;
}
void Build_Max_heap(int A[],int n)
{
	for(int i=n/2;i>=0;i--)
	{
		Max_Heapify(A,i,n);
	}
}
void heapSort(int A[],int n)
{
	int x=n;
	Build_Max_heap(A,n);
	for(int i=n-1;i>=1;i--)
	{
		swap(A[0],A[i]);
		n=n-1;
		Max_Heapify(A,0,n);
	}
}
int main()
{
	int Arr[]={4,1,3,2,16,9,10,14,8,7};
	int n=sizeof(Arr)/sizeof(Arr[0]);
	//int *A=Max_Heapify2(Arr,1,n);
	//heapify(Arr,n,1);
	heapSort(Arr,n);
	for(int i=0;i<n;i++) cout<<Arr[i]<<"  ";
	return 0;
}

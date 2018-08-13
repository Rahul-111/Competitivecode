#include<iostream>
#include<stdlib.h>
using namespace std;
int Partition(int A[],int start,int end)
{
	int pivot=A[end];
	int pIndex=start;
	
	for(int i=start;i<end;i++)
	{
		if(A[i]<=pivot)
		{
			swap(A[i],A[pIndex]);
			pIndex++;
		}
	}
	swap(A[pIndex],A[end]);
	return pIndex;
}
/*int random(int min, int max) //range : [min, max)
{
   static bool first = true;
   if (first) 
   {  
      srand( time(NULL) ); //seeding for the first time only!
      first = false;
   }
   return min + rand() % (( max + 1 ) - min);
}*/
int RandomPartition(int A[],int start,int end)
{
	int pivot=A[end];
	int pIndex=start + ( rand() % ( end - start + 1 ) );
	
	swap(A[pIndex],A[end]);
	
	Partition(A,start,end);
}
void QuickSort(int A[],int start,int end)
{
	if(start>=end)
			return ;
	int pIndex = RandomPartition(A,start,end);
	QuickSort(A,start,pIndex-1);
	QuickSort(A,pIndex+1,end);
	
}

int main()
{
	int arr[]={7,1,2,6,8,5,4};
	int n=sizeof(arr)/sizeof(arr[0]);
	
	QuickSort(arr,0,n-1);
	for(int i=0;i<n;i++) cout<<arr[i]<<"  ";
}

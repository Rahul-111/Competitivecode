//selection sort
#include<iostream>
#include<conio.h>
#include<stdio.h>
using namespace std;
void selectionSort(int a[],int n)
{	for(int i=0;i<n-1;i++)
	{	
		int iMin=i;
		for(int j=i+1;j<n;j++)
		{	
			if(a[j]<a[iMin])
			{	iMin=j;
			}
		}	
		int temp=a[i];
		a[i]=a[iMin];
		a[iMin]=temp;
	}
}
int main()
{	int a[9]={9,8,7,6,5,4,3,2,1};
	int n=sizeof(a)/sizeof(a[0]);
	selectionSort(a,n);
	for(int i=0;i<n;i++)
	{	
		cout<<a[i]<<"\t";
	}
	return 0;
}


#include<iostream>
#include<conio.h>
#include<stdio.h>
using namespace std;
void insertionSort(int a[],int n)
{		
	for(int i=1;i<n;i++)
	{
		int hole=i;
		int value=a[i];
		
		while(hole>0 && a[hole-1]>value)
		{
			a[hole]=a[hole-1];
			hole--;
		}
		a[hole]=value;
	}
}
int main()
{	int a[9]={1,2,3,4,5,6,7,8,9};
	int n=sizeof(a)/sizeof(a[0]);
	insertionSort(a,n);
	for(int i=0;i<n;i++)
	{	
		cout<<a[i]<<"\t";
	}
	return 0;
}

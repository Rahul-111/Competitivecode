#include<iostream>
using namespace std;
int main()
{
	int n;
	cin>>n;
	cout<<"pattern"<<endl;
//	pattern
//	*****
//	****
//	***
//	**
//	*

	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n-i+1;j++)
		{
			cout<<"*";
		}
		cout<<endl;
	}
	cout<<endl;
	cout<<"Pattern"<<endl;
//	Pattern
//
//    *
//   ***
//  *****
// *******
//*********

	for(int i;i<=n;i++)
	{
		for(int j=1;j<=2*n-1;j++)
		{
			if(n-i<j && j<n+i)
				cout<<"*";
			else
				cout<<" ";
		}
		cout<<endl;
	}
	cout<<"\n Pattern"<<endl;
//	 Pattern
//    *
//   * *
//  * * *
// * * * *
//* * * * *
	for(int i=1;i<=n;i++)
	{
		int k=1;
		for(int j=1;j<=2*n-1;j++)
		{
			if(j>=n+1-i && j<=n-1+i && k)
			{
				cout<<"*";
				k=0;
			}
			else
			{
				cout<<" ";
				k=1;
			}
		}
		cout<<endl;
	}
	cout<<"\nPattern"<<endl;
//	Pattern
//*********
//**** ****
//***   ***
//**     **
//*       *

	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=2*n-1;j++)
		{
			if(j<=n+1-i || j>=n-1+i )
			{
				cout<<"*";
			}
			else
			{
				cout<<" ";
			}
		}
		cout<<endl;
	}
	
	cout<<"\nPattern"<<endl;
	
//Pattern
//    1
//   121
//  12321
// 1234321
//123454321

	for(int i=1;i<=n;i++)
	{
		int k=1;
		for(int j=1;j<=2*n-1;j++)
		{
			if(j>=n+1-i && j <=n-1+i)
			{
				cout<<k;
				j<n?k++:k--;
			}
			else
			{
				cout<<" ";
			}
		}
		cout<<endl;
	}
	
	cout<<"Pattern\n";
//	Pattern
//ABCDEDCBA
//ABCD DCBA
//ABC   CBA
//AB     BA
//A       A
	for(int i=1;i<=n;i++)
	{
		char k='A';
		for(int j=1;j<=2*n-1;j++)
		{
			if(j<=n+1-i || j >=n-1+i)
			{
				cout<<k;
				j<n?k++:k--;
			}
			else
			{
				cout<<" ";
				if(j==n)
					k--;
			}
		}
		cout<<endl;
	}
	cout<<"Pattern\n"<<endl;
//	Pattern
//
//   *
//  ***
// *****
//*******
// *****
//  ***
//   *
	int k=0;
	for(int i=1;i<=n;i++)
	{
		int mid=(n + 1)/2;
		i<=mid?k++:k--;
		for(int j=1;j<=n;j++)
		{
			if(j>=mid+1-k && j <=mid-1+k)
			{
				cout<<"*";
			}
			else
			{
				cout<<" ";
			}
		}
		cout<<endl;
	}
//Pattern
//*
//**
//***
//****
//***
//**
//*
	int s=0;
	for(int i=1;i<=n;i++)
	{
		i<=(n+1)/2?s++:s--;
		for(int j=1;j<=(n+1)/2;j++)
		{
			if(j<=s)
			{
				cout<<"*";
			}
			else
			{
				cout<<" ";
			}
		}
		cout<<endl;
	}
//Pattern
//*******
// *****
//  ***
//   *
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<= 2*n-1;j++)
		{
			if(j>=i && j<=8-i)
			{
				cout<<"*";
			}
			else
			{
				cout<<" ";
			}
		}
		cout<<endl;
	}
	return 0;
}

#include<iostream>
#include<cstring>
#define MAX 100
using namespace std;
//Recursive formula to calculate   C(n,k)=C(n-1,k-1)+C(n-1,k)
int coefficient(int n,int k)
{
	if(k==0 || k==n )
		return 1;
	return coefficient(n-1,k-1) + coefficient(n-1,k);
}
//Dynamic Programming 
// Top down approach which known as Tabulation 
int coef(int n,int k)
{
	int a[n+1][k+1];
	for(int i=0;i<=n;i++)
	{
		for(int j=0;j<=min(i,k);j++)
		{
			if(j==0 || j==i)
				a[i][j] = 1;
			else
				a[i][j] = a[i-1][j-1] + a[i-1][j];
		}	
	}	
	return a[n][k];
} 
//Space optimized Solution
int co(int n,int k)
{
	int a[k+1];
	memset(a,0,sizeof(a));
	for(int i=0;i<=n;i++)
	{
		for(int j=0;j<min(i,j);j++)
			a[j] = a[j] + a[j-1];
	}
	return a[k];
}
int main()
{
	int n=5,k=3;
	cout<<"Coefficient = :"<<coefficient(n,k);
	cout<<endl;
	cout<<"Coefficient = :"<<coef(n,k);
}

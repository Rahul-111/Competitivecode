#include<iostream>
using namespace std;
int eggDrop(int n,int k)
{
	if(n==1 || n==0)
		return n;
	if(k==1)
		return n;
	int x,res,min=INT_MAX;
	for(x=1;x<=n;x++)
	{
		res=1 + max(eggDrop(x-1,k-1),eggDrop(n-x,k));
		if(res < min)
			min=res;
	}
	return min;
}
int EggDrop(int n,int k)
{
	int a[n+1][k+1];
	for(int j=1;j<=k;j++)
	{
		a[1][j] = 1;
	}
	for(int i=1;i<=n;i++)
	{
		a[i][1] = i;
	}
	
	for(int i=2;i<=n;i++)
	{
		for(int j=2;j<=k;j++)
		{
			a[i][j] = INT_MAX;
			for(int x=1;x<=i;x++)
			{
				int temp=1+max(a[x-1][j-1],a[i-x][j]);
				if(temp< a[i][j])
					a[i][j]=temp;
			}
		}
	}
	return a[n][k];
}
int main()
{
	int no=8,egg=4;
	cout<<"No of trail "<<eggDrop(no,egg);
	cout<<"\nDynamic Programming Approach\n";
	cout<<"No of trail "<<EggDrop(no,egg);
	return 0;
}

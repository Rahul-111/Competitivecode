#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
	int n;
	cin>>n;
	int a[n];
	int count;
	for(int i=0;i<n;i++)
		cin>>a[i];
		
	sort(a,a+n);
	
	//for(int i=0;i<n;i++)
	//	cout<<a[i]<<"\t";
	
	for(int k=n-1;k>1;k--)
	{
		int i=0; 
		int j=k-1;
		
		while(i<j)
		{
			if(a[k]>a[i]+a[j])
			{
				count+=j-i;
				i++;
			}
			else
				j--;
		}
	}	
	cout<<count;
	return 0;	
}

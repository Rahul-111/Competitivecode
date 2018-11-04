#include<iostream>
#include<cmath>
using namespace std;
int main()
{
	int n;
	cin>>n;
	float a[n]={0.0};
	int x1,y1,x2,y2,x3,y3;
	for(int i=0;i<n;i++)
	{
		cin>>x1>>y1>>x2>>y2>>x3>>y3;
		a[i]=fabs((x1*y2+x2*y3+x3*y1-x1*y3-x3*y2-x2*y1)/2);
	}
	for(int i=0;i<n;i++)
		cout<<a[i]<<" ";
	cout<<endl;
	float min=a[n-1];
	int minindex=n-1;
	float max=a[n-1];
	int maxindex=n-1;
	for(int i=n-1;i>=0;i--)
	{
		if(min > a[i])
		{
			min=a[i];
			minindex=i;
		}
	}
	for(int i=n-1;i>=0;i--)
	{
		if(max < a[i])
		{
			max=a[i];
			maxindex=i;
		}
	}
	cout<<minindex+1<<" "<<maxindex+1<<endl;
	return 0;
}

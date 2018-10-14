#include<iostream>
using namespace std;
/*recusive approach*/
int activitySelection(int s[],int f[],int i,int j)
{
	int m=i+1;
	while(s[m]<f[i] && m<j)
		m=m+1;
	if(m<=j)
		return 1+activitySelection(s,f,m,j);
	else 
		return 0;
}
int activity(int s[],int f[],int n)
{
	int i=0,count=1;
	cout<<"Following activities are selected "; 
  
    // The first activity always gets selected  
    cout<<i; 
	for(int m=1;m<n;m++)
	{
		if(s[m]>=f[i])
		{
			count++;
			cout<<"\t"<<m;
			i=m;
		}
	}
	cout<<endl;
	return count;
}
int main()
{
	int s[]={1,3,0,5,3,5,6,8,8,2,12};
	int f[]={4,5,6,7,8,9,10,11,12,13,14};
	int n=sizeof(s)/sizeof(s[0]);
	cout<<activitySelection(s,f,0,n);
	cout<<endl;
	cout<<activity(s,f,n);
	return 0;
}

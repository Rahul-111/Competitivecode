#include<iostream>
using namespace std;
#define NUM_STATION 4
int carAssembly(int a[][NUM_STATION],int t[][NUM_STATION],int e[],int x[])
{
	
	int T1[NUM_STATION],T2[NUM_STATION],L1[NUM_STATION],L2[NUM_STATION];
	
	T1[0] = e[0] + a[0][0]; // time taken to leave first station in line 1 
    T2[0] = e[1] + a[1][0]; // time taken to leave first station in line 2
    
    for(int i=1;i<NUM_STATION;i++)
    {
    	if(T1[i-1] + a[0][i] <= T2[i-1] + t[1][i] + a[0][i])
    	{
    		T1[i] = T1[i-1] + a[0][i];
    		L1[i] = 1;
		}
		else
		{
			T1[i] = T2[i-1] + t[1][i] + a[0][i];
			L2[i] = 2;
		}
		if(T2[i-1] + a[1][i] <= T1[i-1] + t[0][i] + a[1][i])
		{
			T2[i] = T2[i-1] + a[1][i];
			L2[i]=2;
		}
		else
		{
			T2[i] = T1[i-1] + t[0][i] + a[1][i];
			L2[i] = 1;
		}
	}
	int f,l;
	if(T1[NUM_STATION-1]+x[0] < T2[NUM_STATION -1] + x[1])
	{
		f = T1[NUM_STATION-1]+x[0]; 
		l=1;
	}
	else
	{
		f = T2[NUM_STATION-1]+x[1];
		l=2;
	}
	cout<<"Line "<<l<<"  Station "<<NUM_STATION<<endl;
	int i=l;
	for(int j= NUM_STATION-1;j>=1;j--)
	{
		if(i==1)
		{
			i=L1[j];
			cout<<"Line "<<i<<"  Station "<<j<<endl;
		}
		else
		{ 
			i=L2[j];
			cout<<"Line "<<i<<" Station "<<j<<endl;
		}
	
	}
	return f;
}
int main()
{
	int a[][NUM_STATION] = {{4, 5, 3, 2}, 
                {2, 10, 1, 4}}; 
    int t[][NUM_STATION] = {{0, 7, 4, 5}, 
                {0, 9, 2, 8}}; 
    int e[] = {10, 12}, x[] = {18, 7};
    cout<<"\n"<<carAssembly(a,t,e,x);
    return 0;
}

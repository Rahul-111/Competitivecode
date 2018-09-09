#include<iostream>
using namespace std;
#define num_station 4

int assembleLineScheduling(int a[][num_station],int t[][num_station],int *e,int *x)
{
	int T1[num_station], T2[num_station], i;
	T1[0]=e[0]+a[0][0]; 	// time taken to leave first station in line 1 
	T2[0]=e[1]+a[1][0];		// time taken to leave first station in line 2
	
	// Fill tables T1[] and T2[] using the above given recursive relations 
    for (i = 1; i < num_station; ++i) 
    { 
        T1[i] = min(T1[i-1] + a[0][i], T2[i-1] + t[1][i] + a[0][i]); 
        T2[i] = min(T2[i-1] + a[1][i], T1[i-1] + t[0][i] + a[1][i]); 
    } 
    // Consider exit times and retutn minimum 
    return min(T1[num_station-1] + x[0], T2[num_station-1] + x[1]);
}
int main()
{
	int a[][num_station]={{4,5,3,2},{2,10,1,4}};
	
	int t[][num_station]={{0,7,4,5},{0,9,2,8}};
	
	int e[]={10,12};
	int x[]={18,7};
	
	cout<<"Minimun time required  "<<assembleLineScheduling(a,t,e,x);
	
	return 0;	
}

#include<iostream>
#include<algorithm>
using namespace std;
struct Job
{
	char id;
	int dealine, profit;
};
bool campareProfit(Job j1,Job j2)
{
	return (j1.profit > j2.profit);
}
void printJobSequence(Job arr[],int n)
{
	sort(arr,arr+n,campareProfit);
	
	int result[n]; // To store result (Sequence of jobs) 
    bool slot[n];  // To keep track of free time slots 
  
  	// Initialize all slots to be free 
    for (int i=0; i<n; i++) 
        slot[i] = false;
    for(int i=0;i<n;i++)
    {
    	for(int j=min(n,arr[i].dealine)-1;j>=0;j--)
    	{
    		if(slot[j]==false)
    		{
    			result[j]=i;
    			slot[j]=true;
    			break;
			}
		}
	}
	//print the result
	for(int i=0;i<n;i++)
	{
		if(slot[i])
			cout<<arr[result[i]].id<<"  ";
	}
}
int main()
{
	 Job arr[]={{'a',2,100},{'b',1,19},{'c',2,27},
	 			{'d',1,25} , {'e',3,15} };
	 int n =sizeof(arr)/sizeof(arr[0]);
	 cout<<"Maximum Profit Job Sequence\t";
	 printJobSequence(arr,n);
	 return 0;
};
// Time complexity is O(n*n)


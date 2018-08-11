#include<iostream>

using namespace std;

int main()
{
	int test;
	cin>>test;
	while(test--)
	{
		int n;
		cin>>n;
		int arr[n];
		for(int i=0;i<n;i++) cin>>arr[i];
		int count=0;
		for (int i=0; i<n; i++)
    	{
        // Check if the picked element is already printed
        	int j;
        	for (j=0; j<i; j++)
           		if (arr[i] == arr[j])
               		break;
 
    	    // If not printed earlier, then print it
        	if (i == j)
          		count++;
    	}
    	cout<<"\n"<<count;
	}
	return 0;
}

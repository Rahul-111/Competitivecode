#include<iostream>

using namespace std;

int main () 
{	int test,n,m;
	cin>>test;
    while(test--)
    {	
    	cin>>n>>m;
    	for (int i=n; i<=m; i++) 
    	{	
    		if(i==1)
    			continue;
        	bool prime=true;
        	for (int j=2; j*j<=i; j++)
        	{
            	if (i % j == 0) 
            	{
                	prime=false;
                	break;    
           		}
        	}   
        if(prime) cout << i << " ";
    	}
    	cout<<"\n";
	}
    return 0;
}

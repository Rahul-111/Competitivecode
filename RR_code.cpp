#include <iostream>
#include <string.h>
using namespace std;
int main ()
{
    int t;
    cin>>t;
    while(t--)
	{
        long int n, k, ans, i, j;
        cin>>n>>k>>ans;
        long int a[n];
        for(i=0;i<n;i++){
            cin>>a[i];
        }
        string s;
		cin>>s;
        if(k!=0)
		{
        	if(s=="AND")
			{
                for(i=0;i<n;i++)
				{
                    ans=ans&a[i];
                }
        	}
			else if(s=="OR")
			{
            	for(i=0;i<n;i++)
				{
                    ans=ans|a[i];
                }
        	}
			else
			{
            	if(k%2!=0)
				{
           			for(i=0;i<n;i++)
					{
                    	ans=ans^a[i];
            		}
        		}
        	}
        }
        cout<<ans<<endl;
    }
    return 0;
}

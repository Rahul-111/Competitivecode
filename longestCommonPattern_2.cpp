#include<bits/stdc++.h>
using namespace std;
int main()
{
    int A[62];
    int B[62];
    int t;
    scanf("%d",&t);
    while(t--)
    {
        memset(A,0,sizeof A);
    	memset(B,0,sizeof B);
        string a,b;
        cin>>a>>b;
        int l1=a.length();
        int l2=b.length();
        int i=0;
        int y;
        for(i=0;i<l1;i++)
        {
            	if((a[i]>='A')&&(a[i]<='Z'))
               	{
				   y=a[i]-65;
                   A[y]++;
				}
             	else  if((a[i]>='a')&&(a[i]<='z'))
                {
                    y=a[i]-71;
                    A[y]++;
                }
                else
                {
                    y=a[i]+4;
                    A[y]++;
                }
        }
        for(i=0;i<l2;i++)
        {
             	if((b[i]>='A')&&(b[i]<='Z'))
               	{	
                   y=b[i]-65;
                   B[y]++;
               	}
              	else if((b[i]>='a')&&(b[i]<='z'))
                {
                    y=b[i]-71;
                    B[y]++;
                }
                else
                {
                    y=b[i]+4;
                    B[y]++;
                }
        }
        long long int count=0;
        for(i=0;i<62;i++)
        {
            count=count+min(A[i],B[i]);
        }
        cout<<count<<endl;
    }
}

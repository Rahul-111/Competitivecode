#include<iostream>
#include<cstring>
using namespace std;
int main()
{
	int t,l,L[26],R[26],flag;
	cin>>t;
	string s;
	while(t--)
	{	
		cin>>s;
		l=s.size();
		
		for(int i=0;i<26;i++)
		{
			L[i]=0;
			R[i]=0;
		}
		
		if(l%2==0)
		{
			for(int i=0;i<l/2;i++)
			{
				L[s[i]-97]++;
				R[s[(l/2)+i]-97]++;
			}
		}
		
		else
		{
			for(int i=0;i<l/2;i++)
			{
				L[s[i]-97]++;
				R[s[(l/2)+i+1]-97]++;
			}
		}
		
		flag=0;
		for(int i=0;i<26;i++)
		{
			if(L[i]!=R[i])
			{
				flag=1;
				break;
			}
			//cout<<L[i]<<"\t"<<R[i]<<"\n";
		}
			if(flag==0){
				cout<<"YES\n";
			}	else{
				cout<<"NO\n";
			}
	}
	return 0;
}

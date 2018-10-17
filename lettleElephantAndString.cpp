#include<iostream>
using namespace std;
int stringMatch(string s1,string s2)
{
	int m=s1.length();
	int n = s2.length();
	int j;
	for(int i=0;i<n-m+1;i++)
	{
		int k=i;
		for(j=0;j<m;j++)
		{
			if(s2[k]!=s1[j])
				break;
			k++;
		}
		if(j==m)
			return 1;
	}
	return 0;
}
int main()
{
	int k,n;
	cin>>k;
	cin>>n;
	
	string s1[k];
	for(int i=0;i<k;i++)
		cin>>s1[i];
	
//	string s2[n];
//	for(int i=0;i<n;i++)
//		cin>>s2[i];
//	cout<<endl;
	for(int i=0;i<n;i++)
	{
		string s2;
		cin>>s2;
		if(s2.length()>=47)
			cout<<"Good";
		else
		{
			int flag=0;
			for(int j=0;j<k;j++)
			{
				if(stringMatch(s1[j],s2))
				{
					flag=1;
					break;
				}
			}
			if(flag==1)
				cout<<"Good";
			else if(flag==0)
				cout<<"Bad";
			cout<<endl;
		}
	}
	return 0;
}

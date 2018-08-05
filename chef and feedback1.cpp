#include<iostream>
#include<cstring>
using namespace std;
int main()
{
	int t;
	char arr[100000];
	cin>>t;
	while(t--)
	{	int flag=0;
		cin>>arr;
		for(int i=0;i<strlen(arr);i++)
		{
			if((arr[i]=='1'&&arr[i+1]=='0'&&arr[i+2]=='1')||(arr[i]=='0'&&arr[i+1]=='1'&&arr[i+2]=='0'))
			{	flag=1;
				break;
			}
			else
			flag=0;
		}
		if(flag)
		cout<<"Good\n";
		else
		cout<<"Bad\n";
	}
	return 0;
} 

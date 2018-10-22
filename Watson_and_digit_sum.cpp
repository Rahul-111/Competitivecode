#include<iostream>
using namespace std;

int main()
{
	int t,d;
	cin>>t;
	while(t--)
	{
		cin>>d;
		cout<<(d%9)+1<<endl;
	}
	return 0;	
}

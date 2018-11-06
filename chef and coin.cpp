#include<iostream>
using namespace std;
int main()
{
	int t;
	cin>>t;
	int n;
	while(t--)
	{
		cin>>n;
		if(n%6==0)
			cout<<"Misha"<<endl;
		else
			cout<<"Chef"<<endl;
	}
	return 0;
}

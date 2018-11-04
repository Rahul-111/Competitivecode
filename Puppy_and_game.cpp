#include<iostream>
using namespace std;
int game(int a,int b)
{
	if(a%2==0 || b%2==0)
		return 1;
	else
		return 0;
}
int main()
{
	int t;
	cin>>t;
	int a,b;
	while(t--)
	{
		cin>>a>>b;
		int i=game(a,b);
		if(i==1)
			cout<<"Tuzik"<<endl;
		else
			cout<<"Vanka"<<endl;
	}
	return 0;
}

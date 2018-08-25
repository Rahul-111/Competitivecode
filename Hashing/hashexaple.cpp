#include<iostream>
#include<vector>
using namespace std;


vector <string > hashtable[100];


void insert(string s,int i)
{
	hashtable[i].push_back(s);
}
void search(int n)
{
	cout<<hashtable[n][0]<<"\n";
}
int main()
{
	int n;
	cin>>n;

	while(n--)
	{
		int i;
		cin>>i;
		string s;
		cin>>s;
		insert(s,i);
	}
	int x;
	cin>>x;
	while(x--)
	{
		int t;
		cin>>t;
		search(t);
	}
	return 0;
}

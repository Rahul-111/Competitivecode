#include <iostream>
using namespace std;
#include<bits/stdc++.h>
int main() 
{
int t;
cin>>t;
while(t--)
{
int n,apples;
cin>>n;
set<int>s;
while(n--)
{
cin>>apples;
s.insert(apples);
}
cout<<s.size()<<endl;
}
	return 0;
} 

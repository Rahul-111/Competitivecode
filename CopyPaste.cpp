#include <iostream>
using namespace std;
#include<bits/stdc++.h>
int main() 
{
int t;
cin>>t;
while(t--)
{
int n,i,a;
cin>>n;
set<int>s;
while(n--)
{
cin>>a;
s.insert(a);
}
cout<<s.size()<<endl;
}
 
	return 0;
} 

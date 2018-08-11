#include <iostream>
using namespace std;
#include<bits/stdc++.h>
int main() 
{
int t,k,d,r,i;
cin>>t;
while(t--)
{
cin>>k;
d=k%25;
r=k/25;
if(d>0)
{
for(i=d;i>=0;i--)
printf("%c",i+97);
}
while(r--)
{
cout<<"zyxwvutsrqponmlkjihgfedcba";
}
cout<<endl;
}
	return 0;
} 

#include<iostream>
using namespace std;

int gcd(int a,int b)
{
   int t;
   while(b)
   {
      t=a;
      a=b;
      b=t%b;
   }
   return a;
}
int main()
{
   int t,m,n,a,ans;
   cin>>t;
   while(t--)
   {
      cin>>n;
      ans=0;
      for(int i=0;i<n;i++)
      {
         cin>>a;
         ans=gcd(a,ans);
      }
      cout<<endl;
      if(ans==1)
         cout<<n;
      else
         cout<<"-1";
    cout<<endl;
   }
   return 0;
}

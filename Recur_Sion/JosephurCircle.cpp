#include <bits/stdc++.h>
using namespace std;
int josephus(int n, int k);
int main() {
	
	int t;
	cin>>t;
	while(t--)
	{
		int n,k;
		cin>>n>>k;
		cout<<josephus(n,k)<<endl;
	}
	return 0;
}
/*This is a function problem.You only need to complete the function given below*/
/*You are required to complete this method */
int helper(int n,int k){
    if(n==1)
        return 0;
    return (helper(n-1,k)+k)%n;
}
int josephus(int n, int k)
{
   //Your code here
    int ans=helper(n,k);
    return ans+1;
}

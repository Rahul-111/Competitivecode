#include<iostream>
using namespace std;
int min(int x,int y,int z)
{
	return min(min(x,y),z);
}
int editDistance(string str1,string str2,int m,int n)
{
	if(m==0)
		return n;
	if(n==0)
		return  m;
	if(str1[m-1]==str2[n-1])
		return editDistance(str1,str2,m-1,n-1);
	return 1+min(editDistance(str1,str2,m,n-1),//insert
	editDistance(str1,str2,m-1,n),//remove
	editDistance(str1,str2,m-1,n-1)//replace
	);
	//O(3^m) operations.
}
int editDisDy(string str1,string str2,int m,int n)
{
	int dp[m+1][n+1];
	for(int i=0;i<=m;i++)
	{
		for(int j=0;j<=n;j++)
		{
			// If first string is empty, only option is to 
            // isnert all characters of second string
			if(i==0)
				dp[i][j]=j;
			// If second string is empty, only option is to 
            // remove all characters of second string
			else if(j==0)
				dp[i][j]=i;
			// If last characters are same, ignore last char 
            // and recur for remaining string
			else if(str1[i-1]==str2[j-1])
				dp[i][j]=dp[i-1][j-1];
			// If the last character is different, consider all 
            // possibilities and find the minimum
			else
				dp[i][j]=1+min(dp[i-1][j],dp[i][j-1],dp[i-1][j-1]);
		}
	}
	//Time Complexity: O(m x n)
	//Auxiliary Space: O(m x n)
	return dp[m][n];
}
int main()
{
	string str1="Sunday";
	string str2="Saturday";
	cout<<editDistance(str1,str2,str1.length(),str2.length());
	cout<<"\nUsing Dynamic Programming   ";
	cout<<editDisDy(str1,str2,str1.length(),str2.length());
	return 0;
}

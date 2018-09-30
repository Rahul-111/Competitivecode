#include<iostream>
#include<cstring>
using namespace std;
//Recursive solution 
int lcs(char A[],char B[],int i,int j,int m,int n)
{
	if(i==m || j==n)
		return 0;
	if(A[i]==B[j])
		return 1 + lcs(A,B,i+1,j+1,m,n);
	else
		return max(lcs(A,B,i+1,j,m,n),lcs(A,B,i,j+1,m,n));
}
int l_cs(char A[],char B[],int m,int n)
{
	int a[m+1][n+1];
	for(int i=0;i<=m;i++)
	{
		for(int j=0;j<=n;j++)
		{
			if(i==0 || j==0)
				a[i][j]=0;
			else if(A[i-1]==B[j-1])
				a[i][j]=1+a[i-1][j-1];
			else
				a[i][j] = max(a[i-1][j],a[i][j-1]);
		}
	}
	return a[m][n];
}
int main()
{
	char A[]="aggtab";
	char B[]="gxtxayb";
	int m=strlen(A);
	int n=strlen(B);
	cout<<"Longest Commonn Subsequence\t"<<lcs(A,B,0,0,m,n);
	cout<<endl;
	cout<<"Longest Commonn Subsequence\t"<<l_cs(A,B,m,n);
	return 0;
}

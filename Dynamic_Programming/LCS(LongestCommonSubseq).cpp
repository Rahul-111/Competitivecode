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
	//print LCS
	int index = a[m][n];
	
	// Create a character array to store the lcs string 
   	char lcs[index]; 
   
	int i = m, j = n; 
   	while (i > 0 && j > 0) 
   	{ 
      	// If current character in X[] and Y are same, then 
      	// current character is part of LCS 
      	if (A[i-1] == B[j-1]) 
      	{ 
          lcs[index-1] = A[i-1]; // Put current character in result 
          i--; j--; index--;     // reduce values of i, j and index 
      	} 
  
      	// If not same, then find the larger of two and 
     	// go in the direction of larger value 
      	else if (a[i-1][j] > a[i][j-1]) 
         	i--; 
    	else
        	j--; 
   	} 
  
   	// Print the lcs 
   	cout << "LCS of " << A << " and " << B << " is " << lcs; 
   	cout<<endl;
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

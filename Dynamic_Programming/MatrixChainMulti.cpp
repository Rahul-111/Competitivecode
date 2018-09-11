#include<iostream>
#include<limits.h>
using namespace std;
int matrixChainMulti(int p[],int i,int j)
{
	if(i==j)
		return 0;
	int k;
	int min =INT_MAX;
	int count;
	// place parenthesis at different places between first 
    // and last matrix, recursively calculate count of 
    // multiplications for each parenthesis placement and 
    // return the minimum count
    for (k = i; k <j; k++) 
    { 
        count =matrixChainMulti(p, i, k) + 
            matrixChainMulti(p, k+1, j) + 
            	p[i-1]*p[k]*p[j]; 
  
        if (count < min) 
            min = count; 
    } 
    return min;
}
int dynamicMatrixMulti(int p[],int n)
{
	/* For simplicity of the program, one extra row and one 
       extra column are allocated in m[][].  0th row and 0th 
       column of m[][] are not used */
    int m[n][n];
    int i, j, k, l, q;
    // cost is zero when multiplying one matrix. 
    for (i=1; i<n; i++) 
        m[i][i] = 0;
    //Here L is chain length. It varies from length 2 to length n.    
	for(l=2;l<n;l++)
	{
		for(i=1;i<n-l+1;i++)											//1,1=0	     2,2=0	      3,3=0	     4,4=0
		{																//1,2=20000	 2,3=10000	  3,4=8000	
			j=i+l-1;
			m[i][j]= INT_MAX;											//1,3=15000	 2,4=50000	
			for(k=i;k<=j-1;k++)                                         //1,4=19000
			{
				q = m[i][k] + m[k+1][j] + p[i-1]*p[k]*p[j];
                if (q < m[i][j])
                {
                    m[i][j] = q;    //if number of multiplications found less that number will be updated.
                }													
			}
		}
	}
	return m[1][n-1]; 		//returning the final answer which is M[1][n]
}
int main()
{
	int arr[] = {1,2,3,4,3};
	int n=sizeof(arr)/sizeof(arr[0]);
	cout<<"Minimun number of multiplication  "<<matrixChainMulti(arr,1,n-1);
	cout<<"\nMinimun number of multiplication using dynamic programming  "<<dynamicMatrixMulti(arr,n);
	return 0;
}

#include <cstdio>

int main()
{
	// input number of tests
	int T;
	scanf("%d",&T);
	// loop over tests
	for(int t=0;t<T;t++)
	{
		int N,C,Q;
		scanf("%d%d%d",&N,&C,&Q);
		// loop over flip operations
		for(int q=0;q<Q;q++)
		{
			// input flip segment
			int U,V;
			scanf("%d%d",&U,&V);
			// flipping position of coin if needed 
			if(U<=C && C<=V)
				C=U+V-C;
		}
		printf("%d\n",C);
	}
	return 0;
}

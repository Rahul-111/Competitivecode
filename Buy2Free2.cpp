#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
	int test;
	cin>>test;
	while(test--)
	{
		int N;
		cin>>N;
		int A[N];
		for(int i=0;i<N;i++) cin>>A[i];
		int C=0;
		sort(A,A+N);
		reverse(A,A+N);
		for(int i=0;i<N;i++)
		{
			if(i%4<2)
				C+=A[i];
		}
			cout<<C<<endl;
	}		

	return 0;
}

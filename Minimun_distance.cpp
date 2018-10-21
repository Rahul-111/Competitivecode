#include<iostream>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{	
		float Ds,Dt,D;
		cin>>Ds>>Dt>>D;
		if(D<Ds+Dt)
			printf("%.4f",0);
		else
			printf("%.4f",D-Ds-Dt);
	}
	return 0;
}

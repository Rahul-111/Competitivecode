//#include<iostream>
#include<stdio.h>
//#include<conio.h>
//using namespace std;

int main()
{
	int test;
	scanf("%d",&test);
	while(test--)
	{
		int k,i;
		scanf("%d",&k);
		
		for(i=0;i<=k;i++)
		{
			printf("%c",97+k-i);
		}
	}
	return 0;
}

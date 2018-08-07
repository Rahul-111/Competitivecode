#include<iostream>
using namespace std;
// Generating all the strings of n bits O(2^n)
char A[10]; 
void Binary(int n)
{
	if(n<1)
		cout<<A<<"\t";
	else{
		A[n-1]='0';
		Binary(n-1);
		A[n-1]='1';
		Binary(n-1);
	}
}
int main()
{	
	int n;
	cout<<"Enter number of bit\t";
	cin>>n;
	char A[n];
	Binary(n);
	return 0;
}

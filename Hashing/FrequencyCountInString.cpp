#include<iostream>
#include<string.h>
using namespace std;
void CountFrq(string S)
{
	for(int i=0;i<strlen(S);++i)
		cout<<i<<"  ";
}
int main()
{
	string s;
	s='abaabcca';
	CountFrq(s);
	return 0;
}

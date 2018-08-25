#include<iostream>
#include<vector>
#include<stdlib.h>
using namespace std;
//Assumption: Hash function will return an integer from 0 to 19.
vector <string > HashTable[20];
	int Hashsize=20;
int hashfunc(string s)
{
	return s.length();
}
void insertHash(string s)
{
	int index = hashfunc(s);
	HashTable[index].push_back(s);
}
void search(string s)
{
	int index = hashfunc(s);
	for(int i=0;i<HashTable[index].size();i++)
	{
		if(HashTable[index][i] == s)
		{
			cout<< s << " is found "<< endl;
			return ;
		}
	}
			cout<< s << "  is not found "<<endl;
}
int main()
{
	string s="absak";
	insertHash(s);
	s="as";
	insertHash(s);
	s="abc";
	insertHash(s);
	search("as");
	return 0;
}

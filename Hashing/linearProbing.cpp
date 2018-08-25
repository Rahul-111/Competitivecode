#include<iostream>
#include<vector>
/*
Assumption

There are no more than 20 elements in the data set.
Hash function will return an integer from 0 to 19.
Data set must have unique elements.
*/
using namespace std;
string hashTable[21];
int hashTableSize = 21;
int hashFunc(string s)
{
	return s.length();
}
void insert(string s)
{
    //Compute the index using the hash function
    int index = hashFunc(s);
    //Search for an unused slot and if the index will exceed the hashTableSize then roll back
    while(hashTable[index] != "")
        index = (index + 1) % hashTableSize;
    hashTable[index] = s;
}

void search(string s)
{
    //Compute the index using the hash function
    int index = hashFunc(s);
    //Search for an unused slot and if the index will exceed the hashTableSize then roll back
    while(hashTable[index] != s and hashTable[index] != "")
        index = (index + 1) % hashTableSize;
    //Check if the element is present in the hash table
    if(hashTable[index] == s)
        cout << s << " is found!" << endl;
    else
        cout << s << " is not found!" << endl;
}
int main()
{
	string s="dada";
	insert(s);
	insert(s="aa");
	search(s);
	return 0;
}

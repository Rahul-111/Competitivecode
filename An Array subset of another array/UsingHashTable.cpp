#include<iostream>
#include<algorithm>
#include<map>
using namespace std;

bool isSubset(int arr1[],int arr2[],int m,int n)
{	
	map<int ,int> h;
	for(int i=0;i<m;i++)
	{
		h.insert(pair <int , int >(arr1[i],1));
	}
	cout<<h.end();
	map<int, int>::iterator it ;
	for(int i=0;i<n;i++)
	{	
		it=h.find(arr2[i]);
		if(it==h.end())  //mean if not contain
			return false;
	}
	return true;
}
int main()
{
	int arr1[]={11,1,13,21,3,7};
	int arr2[]={11,1,3,7,5};
	
	int m=sizeof(arr1)/sizeof(arr1[0]);
	int n=sizeof(arr2)/sizeof(arr2[0]);
	
	if(isSubset(arr1,arr2,m,n)) cout<<"arr2[] is a subset of arr1[]";
	else cout<<"arr2[] is not a subset of arr1[]";
}

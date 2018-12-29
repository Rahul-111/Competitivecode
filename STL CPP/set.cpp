#include<iostream>
#include<set>
#include<algorithm>
using namespace std;
int main()
{
	set<int > s;
	s.insert(1);
	s.insert(5);
	s.insert(3);
	s.insert(-1);
	s.insert(-10);
	
//	for(int x: s)
//		cout<<x<<" ";
//	cout<<endl;

	for(set<int >::iterator it = s.begin();it!=s.end();it++)
		cout<<*it<<" ";
	cout<<endl;
	s.insert(2);
	for(set<int >::iterator it = s.begin();it!=s.end();it++)
		cout<<*it<<" ";
	cout<<endl;
	
	//find in SET
	set<int >::iterator it=s.find(-1);
	if(it==s.end())
		cout<<"not present\n";
	else
		{
			cout<<"present\n";
			cout<<*it<<endl;
		}
	set<int >::iterator it2 = s.lower_bound(-1); // first elemnet >= to argument
	set<int >::iterator it3 = s.upper_bound(-1); // first element > in argument
	cout<<*it2<<" "<<*it3<<endl;
	
	set<int >::iterator it4 = s.upper_bound(5);
	if(it4==s.end())
		cout<<"oops! can't find something greater than 5 (largest element)";
	s.erase(1);
	cout<<endl;
	for(set<int >::iterator it5 = s.begin();it5!=s.end();it5++)
		cout<<*it5<<" ";
	cout<<endl;
	return 0;
}

#include<iostream>
#include<vector>
#include<algorithm>
bool f(int x,int y)
{
	return x>y;
}
using namespace std;
int main()
{
	vector<int > A;
	A.push_back(5);
	A.push_back(2);
	A.push_back(0);
	cout<<A[1]<<endl;
	
	sort(A.begin(),A.end()); // O(NlogN)
	
	cout<<A[2]<<endl;
	// 0 2 5
	//O(NlogN)
	bool present = binary_search(A.begin(),A.end(),3);
	A.push_back(100);
	A.push_back(100);
	A.push_back(100);
	A.push_back(123);
	
	vector<int >::iterator it = lower_bound(A.begin(),A.end(),100);// >= 100 O(logN)
	//auto it = lower_bound(A.begin(),A.end(),100);
	vector<int >::iterator it2 = upper_bound(A.begin(),A.end(),100); // > 123 O(logN)
	
	cout<<*it <<" "<<*it2<<endl;
	cout<<it2-it<<endl;
	// print in reverse order
	sort(A.begin(),A.end(),f);
	
	vector<int >::iterator it3;
	for(it3=A.begin();it3!=A.end();it3++)
		cout<<*it3<<" ";
	cout<<endl;
	
	/*for(int x: A)
		cout<<x<<" ";
	cout<<endl;
	*/
}

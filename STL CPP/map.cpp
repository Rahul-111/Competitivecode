#include<iostream>
#include<map>
#include<set>
#include<algorithm>
using namespace std;
void PowerOfstl()
{
//	//[x,y]
//	add[2,3]
//	add[10,20]
//	add[30,400]
//	add[401,450]
//	give me the interval 401
	set<pair<int ,int> > s;
	s.insert({401,450});
	s.insert({10,20});
	s.insert({2,3});
	s.insert({30,400});
	
	int point = 1;
	// if point = 1
	set<pair<int,int> >::iterator it=s.upper_bound({point,INT_MAX});
	if(it==s.begin())
	{
		cout<<"the given point is not lying in any interval..\n";
		return ;
	}
	it--;
	pair<int,int> current = *it;
	if(current.first <=point && point <= current.second)
	{
		cout<<"Yes its present "<<current.first<<" "<<current.second<<endl;
	}
	else{
		cout<<"the given point is not lying in any interval..\n";
	}
}
int main()
{
	map<int ,int> A;
	A[1]=100;
	A[2]=-1;
	A[3]=200;
	A[1000]=1;
	
	map<char,int > cnt;
	string x = "rahul srivastav";
	
	for(int c=0;c<x.length();c++)
		cnt[x[c]]++;
	cout<<cnt['a']<<" "<<cnt['z']<<endl;
	PowerOfstl();
	return 0;
}

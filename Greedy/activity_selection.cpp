#include <bits/stdc++.h>
using namespace std;
//void activity(int s[],int f[],int n)
//{
//	int i=0;
//	cout<<i<<"\t";
//	for(int j=1;j<n;j++)
//	{
//		if(s[j]>=f[i])
//		{
//			cout<<j<<"\t";
//			i=j;
//		}
//	}
//}
// if not given sorted finish time
struct Activity
{
	int start,finish;
};
bool activitycampare(Activity s1,Activity s2)
{
	return (s1.finish < s2.finish);
}
void printactivity(Activity a[],int n)
{
	sort(a,a+n,activitycampare);
	int i=0;
	cout<<"("<<a[i].start<<","<<a[i].finish<<"), ";
	
	for(int j=1;j<n;j++)
	{
		if(a[j].start >= a[i].finish)
		{
			cout << "(" << a[j].start << ", "
              << a[j].finish << "), "; 
          	i = j; 
		}
	}
}
int main()
{
//	int s[]={10, 12, 20};
//    int f[]={20, 25, 30}; 
//	int n=sizeof(f)/sizeof(f[0]);
//	activity(s,f,n);
	Activity a[]={{12,25},{20,30},{10,20}};
	int n=sizeof(a)/sizeof(a[0]);
	printactivity(a,n);
	return 0;
}

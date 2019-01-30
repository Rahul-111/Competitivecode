#include<iostream>
#include<algorithm>
using namespace std;
struct Interval{
	int st;
	int et;
};
bool compare(Interval i1,Interval i2){
	return i1.st < i2.st;
}
int main(){
//	int arr[]={1,3,2,5,7,6};
//	sort(arr,arr+6,greater<int>());
//	for(int i=0;i<6;i++){
//		cout<<arr[i]<<" ";
//	}


//	Interval arr[] = {{6,4},{3,4},{4,6},{8,13}};
//	sort(arr,arr+4,compare);
//	
//	for(int i=0;i<4;i++){
//		cout<<arr[i].st <<" : "<<arr[i].et<<endl;
//	}

	int arr[]={1,3,2,5,7,6};
	sort(arr,arr+6);
	cout<<binary_search(arr,arr+6,2);//binary search return 1 or 0;
	cout<<endl;
	
	cout<<lower_bound(arr,arr+6,3)-arr;	// to get index
	cout<<endl;
	
	
	cout<<__gcd(10,6)<<endl;
	
	int x=10,y=12;
	swap(x,y);
	cout<<x<<" "<<y<<endl;
	return 0;
}

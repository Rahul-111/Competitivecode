#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
	int N,D;
	cin>>N>>D;
	int arr[N],pair=0;
	for(int i=0;i<N;i++) cin>>arr[i];
	
	sort(arr,arr+N);
	//for(int i=0;i<N;i++) cout<<arr[i];
	for(int i=0;i<N-1;)
	{
		if((arr[i+1]-arr[i])<=D)
			{
				pair++;
				i=i+2;
			}
			else{
				i++;
			}
		
	}
	cout<<"\n"<<pair;
	return 0;
}

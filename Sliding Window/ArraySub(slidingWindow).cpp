//print max element from every window of size k
#include<bits/stdc++.h>
#include<deque>
using namespace std;
void bruteForce(int A[],int n,int k){
	for(int i=0;i<n-k+1;i++){
		int maxl=INT_MIN;
		for(int j=0;j<k;j++){
			maxl=max(maxl,A[i+j]);
		}
		cout<<maxl<<" ";
	}
}
void slidingWindow(int A[],int n,int k){
	deque<int > Q;
	int i;
	for(i=0;i<k;i++){
		while(!Q.empty() && A[i] > A[Q.back()]){
			Q.pop_back();
		}
		Q.push_back(i);
	}
	for(;i<n;i++){
		cout<<A[Q.front()]<<" ";
		while(!Q.empty() && (Q.front() <=i-k)){
			Q.pop_front();
		}
		while(!Q.empty() && (A[i] >=A[Q.back()])){
			Q.pop_back();
		}
		Q.push_back(i);
	}
	cout<<A[Q.front()]<<endl;
}
int main(){
	int n,k;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++)
		cin>>arr[i];
	cin>>k;
	bruteForce(arr,n,k);
	slidingWindow(arr,n,k);
	return 0;
}

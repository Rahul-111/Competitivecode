#include<bits/stdc++.h>
using namespace std;
bool binary(int *A,int x,int l,int u){
	while(l<=u){
		int mid=(l+u)/2;
		if(A[mid]==x)
			return true;
		else if(A[mid]<x){
			l=mid+1;
		}
		else if(A[mid]>x){
		u=mid-1;
		}
	}
	return false; 
}
int main(){
	int arr1[]={2,6,6,9,11,13,17};
	int arr2[]={3,6,6,7,10,13,18};
	int arr3[]={4,5,6,6,9,11,13};
	//time complexity O(nlogn)
	vector<int > ans;
	for(int i=0;i<6;i++){
		if(binary(arr2,arr1[i],0,6) &&(binary(arr3,arr1[i],0,6)))
			ans.push_back(arr1[i]);
	}
	cout<<"Answer 1"<<endl;
	for(auto x:ans)
		cout<<x<<" ";
	
	//time complexity O(n)	
	unordered_set<int > H1,H2;
	for(int i=0;i<6;i++){
		H1.insert(arr2[i]);
		H2.insert(arr3[i]);
	}
	
	vector<int > ans2;
	for(int i=0;i<6;i++){
		if(H1.find(arr1[i])!=H1.end()&& H2.find(arr1[i])!=H2.end())
			ans2.push_back(arr1 [i]);
	}
	
	cout<<"\nAnswer 2"<<endl;
	for(auto y:ans2){
		cout<<y<<" ";
	}
	//time complexity O(n)
	int x=0,y=0,z=0;
	int n1=sizeof(arr1)/sizeof(arr1[0]);
	int n2=sizeof(arr2)/sizeof(arr2[0]);
	int n3=sizeof(arr3)/sizeof(arr3[0]);
	vector<int > result;
	
	while(x<n1 || y<n2 || z<n3){
		if(arr1[x]==arr2[y] &&arr2[y]==arr3[z]){
			result.push_back(arr1[x]);
			x++;y++;z++;
		}
		else if(arr1[x] <arr2[y])
			x++;
		else if(arr2[y] <arr3[z])
			y++;
		else 
			z++;
	}
	// it will work for duplicate entries
	cout<<"\nAnswer 3"<<endl;
	for(auto x:result)
		cout<<x<<" ";
	return 0;
}

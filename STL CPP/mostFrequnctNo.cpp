#include<bits/stdc++.h>
using namespace std;
int most_frequent_bysizedivideby2(int A[],int n){
	int count=1;
	for(int i=1;i<n;i++){
		if(A[i]==A[i-1])
		{
			count++;
			if(count > n/2)
			{
				return A[i];
			}
		}
		else{
			count=1;
		}
	}
	return -1;
}
int most_freq(int A[],int n){
	int maxcount=1,maxindex=0;
	int notocheck=A[0];
	int count=1;
	for(int i=1;i<n;i++){
		if(A[i]==A[i-1]){
			count++;
			if(count > maxcount){
				maxcount=count;
				maxindex=i;
			}
			//maxcount=max(maxcount,count);
		}
		else{
			notocheck=A[i];
			count=1;
		}
	}
	return A[maxindex];
}
int mostFrequent(int arr[], int n) 
{ 
    // Insert all elements in hash. 
    map<int, int> hash; 
    for (int i = 0; i < n; i++) 
        hash[arr[i]]++; 
  
    // find the max frequency 
    int max_count = 0, res = -1; 
    for (map<int,int >::iterator it=hash.begin();it!=hash.end();it++) { 
        if (max_count < it->second) { 
            res = it->first; 
            max_count = it->second; 
        } 
    } 
  
    return res; 
} 
int main(){
	int arr[]={ 1, 5, 2, 2, 3, 2, 1 };
	int n=sizeof(arr)/sizeof(arr[0]);
	sort(arr,arr+n);
	cout<<most_frequent_bysizedivideby2(arr,n)<<endl;
	cout<<most_freq(arr,n)<<endl;
	cout<<mostFrequent(arr,n)<<endl;
	return 0;
}

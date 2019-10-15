#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,k;
	cin>>n>>k;
	
	string s[n];
	vector<int> v;
	for(int i=0;i<n;i++){
		cin>>s[i];
		v.push_back(s[i].size());
	}
	sort(v.begin(),v.end());
// 	for(int i=0;i<n;i++)
// 	cout<<v[i]<<" ";

//     cout<<endl;
	string ans;
	cin>>ans;
	int t;
	t=ans.size();
	int minIndex=0;
	for(int i=0;i<n;i++){
		if(v[i]==t){
			minIndex=i+1;
			break;
		}
	}
	int maxIndex=0;
	for(int i=n-1;i>=0;i--){
		if(v[i]==t){
			maxIndex=i+1;
			break;
		}
	}
	if(n==1){
		cout<<"1"<<" "<<"1"<<endl;
	}
	else{
		int min=0;
		for(int i=1;i<=minIndex;i++){
			if(i%k==0 && i!=minIndex){
				min+=5;
			}
			min++;
		}
		
		int max=0;
		for(int i=1;i<=maxIndex;i++){
			if(i%k==0 && i!=maxIndex){
				max+=5;
			}
			max++;
		}
		cout<<min<<" "<<max<<endl;
	}
	return 0;
}

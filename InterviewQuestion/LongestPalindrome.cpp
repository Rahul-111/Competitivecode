#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin>>t;
	while(t--){
		string s;
		cin>>s;
		int n=s.size(),start=0;
		int low,high;
		int lengthOfPalindrome=1;//min length can be 1
		
		for(int i=1;i<n;i++){
		//even length palindrome
		low=i-1;
		high=i;
			while(low>=0 && high<n && s[low]==s[high]){
				if(high-low+1 > lengthOfPalindrome){
					start=low;
					lengthOfPalindrome=high-low+1;
				}
				low--;
				high++;
			}
			
		//odd length palindrome
		low=i-1;
		high=i+1;
			while(low>=0 && high<n && s[low]==s[high]){
				if(high-low+1 >lengthOfPalindrome){
					start=low;
					lengthOfPalindrome=high-low+1;
				}
				low--;
				high++;
			}
		}
		
		for(int i=start;i<start+lengthOfPalindrome;i++){
			cout<<s[i];
		}
		cout<<endl;
	}
	return 0;
}

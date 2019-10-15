#include<iostream>
#include<string>
using namespace std;
//bool AllOdd(string n){
//	for(int i=0;i<n.size();i++){
//		if(int(n[i])%2==0){
//			return false;
//		}
//	}
//	return true;
//}
//bool isEven(char c){
//	if(int(c)%2==0)
//		return true;
//	return false;
//}
//int main(){
//	string n;
//	cin>>n;
//	if(AllOdd(n)){
//		cout<<"-1"<<endl;
//	}else{
//		int ans=0;
//		int index=n.size()-1;
//		for(int i=0;i<n.size()-1;i++){
//			if(isEven(n[i])){
//				swap(n[i],n[index]);
//				ans=max(ans,stoi(n));
//				swap(n[i],n[index]);
//			}
//		}
//		cout<<ans<<endl;
//	}
////	cout<<n<<endl;
//	return 0;
//}
int main(){
	string n;
	cin>>n;
	int last=n.size()-1;
	int ind=n.size();
	
	for(int i=0;i<n.size();i++){
		if((n[i]-'0')%2==0){
			ind =i;
			if(n[last]>n[i])
				break;
		}
	}
	if(ind==last)
		cout<<"-1"<<endl;
	else{
		swap(n[ind],n[last]);
		cout<<n<<endl;
	}
	return 0;
}

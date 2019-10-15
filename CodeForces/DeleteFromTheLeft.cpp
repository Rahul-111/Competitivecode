#include<iostream>
using namespace std;
int main(){
	string x,y;
	cin>>x>>y;
	int i=x.size()-1;
	int j=y.size()-1;
	int match=0;
	while(i>=0 && j>=0){
		if(x[i]==y[j]){
			match++;
			i--;
			j--;
// 			cout<<x[i]<< " "<<y[i]<<endl;
		}
		else{
			break;
		}
	}
// 	cout<<match<<endl;
	cout<<x.size()+y.size()-2*match<<endl;
	
	return 0;
}

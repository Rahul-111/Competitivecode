#include <iostream>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--){
	    string a,b;
	    cin>>a>>b;
	    int f1=1,f2=1;  //indicating Yes    
	    //for clockwise
	    for(int i=0;i<a.size();i++){
	        if(a[i]!=b[(i+a.size()-2)%a.size()]){
	            f1=0;
	        }
	    }
	    //for anticlockwise
	    for(int i=0;i<a.size();i++){
	        if(a[i]!=b[(i+2)%a.size()]){
	            f2=0;
	        }
	    }
	    if(f1==0&&f2==0)
	        cout<<"0"<<endl;
	    else
	        cout<<"1"<<endl;
	    
	}
	return 0;
}

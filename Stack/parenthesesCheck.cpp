#include<bits/stdc++.h>
using namespace std;
bool isOpening(char c){
    if(c=='('||c=='{'||c=='[')
        return true;
    return false;
}
int main()
 {
	//code
	stack<char> s;
	int t;
	cin>>t;
	unordered_map<char,char> M;
	M['}']='{';
	M[')']='(';
	M[']']='[';
	while(t--){
	    char ex[100000];
	    cin>>ex;
//	    cout<<ex<<endl;
	    int i=0;
	    int flag=1;
	    while(ex[i]!='\0'){
	        if(isOpening(ex[i])){
	            s.push(ex[i]);
	        }
	        else{
	            if(s.top()!= M[ex[i]]) {
	                cout<<"not balanced"<<endl;
	                flag=0;
	                break;
	            }
	            if(s.top()== M[ex[i]])
	                s.pop();
	        }
			i++;
	    }
	    if(s.size()==0){
	    	cout<<s.size()<<endl;
	    	cout<<"balanced"<<endl;
		}
	}
	return 0;
}

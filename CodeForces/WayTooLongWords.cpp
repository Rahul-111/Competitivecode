#include<iostream>
using namespace std;
int main(){
        int n;
        cin>>n;
        while(n--){
                string s;
                cin>>s;
                if(s.size()<=10)
                        cout<<s<<endl;
                else{
                        int n=s.size()-2;
                        string ans="";
                        ans+=s[0];
                        string t;
                        t=to_string(n);
                        ans+=t;
                        ans+=s[s.size()-1];
                        cout<<ans<<endl;
                }
        }
        return 0;
}

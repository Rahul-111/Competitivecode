#include <iostream>

using namespace std;
bool isPalindrome(string s){
    int l=0,r=s.size()-1;
    
    while(l<r){
        if(s[l]!=s[r])
            return false;
        l++;
        r--;
    }
    return true;
}
bool allsame(string s){
    for(int i=1;i<s.size();i++){
        if(s[i]!=s[0])
            return false;
    }
    return true;
}
int main()
{
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        
        if(s.size()==1 || allsame(s)){
            cout<<"-1"<<endl;
        }
        else if(!isPalindrome(s)){
            cout<<s<<endl;
        }else if(isPalindrome(s)){
            int mid;
            if(s.size()%2==0){
                mid=s.size()/2 -1;
            }else
                mid=s.size()/2;
                
            for(int i=0;i<s.size();i++){
                if(i==mid)
                    continue;
                if(s[mid]!=s[i]){
                    swap(s[i],s[mid]);
                    break;
                }
            }
            cout<<s<<endl;
        }
    }

    return 0;
}
int main()
{
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        
        set<char> st;
        sort(s.begin(),s.end());
        for(int i=0;i<s.size();i++)
            st.insert(s[i]);
        if(st.size()==1)
            cout<<"-1"<<endl;
        else
            cout<<s<<endl;
        
    }
 
    return 0;
}


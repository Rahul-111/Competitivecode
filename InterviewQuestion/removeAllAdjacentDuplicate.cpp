#include<iostream>
#include<cstring>
using namespace std;

string recur(string s)
{
    if(s.length()==0)
        return "";
    string temp="";
    if(s[0]!=s[1])
    {
        temp+=s[0];
    }
    for(int i=1;i<s.length();i++)
    {
        if(s[i-1]!=s[i] && s[i]!=s[i+1])
             temp+=s[i];
    }
    if(temp.length()<s.length())
        return recur(temp);
    return temp;
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string s,n;
        cin>>s;
        cout<<recur(s)<<endl;
    }
}

#include<bits/stdc++.h>
using namespace std;
int strstr(string ,string);
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string a;
        string b;
        
        cin>>a;
        cin>>b;
        
        cout<<strstr(a,b)<<endl;
    }
}

/*This is a function problem.You only need to complete the function given below*/
/* The function should return position where the target string 
   matches the string str
Your are required to complete this method */
int strstr(string s, string x)
{
     //Your code here
     int flag=0;
     for(int i=0;i<s.length()-x.length()+1;i++){
         int j;
		 for(j=0;j<x.length();j++){
             if(s[i]!=x[j])
                break;
         }
         if(j-1==x.length()){
             return j;
         }
     }
     return -1;
}

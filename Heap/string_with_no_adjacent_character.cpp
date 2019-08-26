#include<bits/stdc++.h>
using namespace std;
struct Node{
    char c;
    int freq;
};
struct compare{
    bool operator() (Node &l,Node &r) 
    { 
        return l.freq < r.freq; 
    } 
};
int main()
 {
	int t;
	cin>>t;
	while(t--){
	    string s;
	    cin>>s;
	    
	    int freq_arr[26]={0};
	    for(int i=0;i<s.length();i++){
	        freq_arr[s[i]-'a']++;
	    }
	    
	    priority_queue<Node,vector<Node>,compare> pq; 
        for (char c = 'a' ; c <= 'z' ; c++){
            if (freq_arr[c-'a']){
                Node x;
                x.c=c;
                x.freq=freq_arr[c-'a'];
                pq.push(x);
            } 
        }
        string str="";
        Node prev{'#',0};
        while (!pq.empty()) { 
        Node k = pq.top(); 
        pq.pop(); 
        str = str + k.c; 
  
        if (prev.freq > 0) 
            pq.push(prev); 
  
        // make current character as the previous 'char' 
        // decrease frequency by 'one' 
        (k.freq)--; 
        prev = k; 
        } 
        if(s.length()!=str.length())
            cout<<"0"<<endl;
        else
            cout<<"1"<<endl;
	}    
	  
	return 0;
}

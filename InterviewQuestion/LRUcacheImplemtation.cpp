#include<bits/stdc++.h>
using namespace std;
class LRUCache{
	public:
		LRUCache(int );
		int get(int );
		void set(int ,int );
};
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
    int n;
    cin>>n;
    LRUCache *l  = new LRUCache(n);
    int q;
    cin>>q;
    for(int i=0;i<q;i++)
    {
        string a;
        cin>>a;
        if(a=="SET")
        {
            int aa,bb;
            cin>>aa>>bb;
            l->set(aa,bb);
        }else if(a=="GET")
        {
            int aa;
            cin>>aa;
            cout<<l->get(aa)<<" ";
        }
    }
    cout<<endl;
    }
}
list<pair<int,int> > L;
unordered_map <int,list<pair<int,int>>::iterator> ma;int csize;
LRUCache::LRUCache(int N)
{
    L.clear();ma.clear();
    csize = N;   
}
void LRUCache::set(int x,int y){
	//x is not present
	if(ma.find(x)==ma.end()){
		if(ma.size()==csize){
			pair<int,int> last = L.back();
			L.pop_back();
			ma.erase(last.first);
		}
	}
	else{
		list<pair<int,int>>::iterator it = ma[x];
		L.erase(it);
		ma.erase(x);
	}
	
	L.push_front({x,y}); //make_pair(x,y)
	ma.insert(make_pair(x,L.begin()));//{x,y}
}
int LRUCache::get(int x){
	if(ma.find(x)==ma.end())
		return -1;
	auto it = ma[x];
	int y=it->second;
	L.erase(it);
	L.push_front({x,y});
	ma[x]=L.begin();
	return y;
}



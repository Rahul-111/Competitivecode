#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int migratoryBirds(vector<int> arr) {
    int n = arr.size();
    int m = *max_element(arr.begin(), arr.end());
    vector<int > v(n,0);
    for(auto j:arr)
        v[j]+=1;
    int ans;
    int max = *max_element(v.begin(), v.end());    
    for(int i=1;i<=m;i++)
        if(v[i]==max)
        {
            ans=i;
            break;
        }
    return ans;
}
int main()
{
	int n=5;
	vector<int > v;//1 4 4 4 5 3
	v.push_back(1);
	v.push_back(4);
	v.push_back(4);
	v.push_back(4);
	v.push_back(5);
	v.push_back(3);
	
	int max=*max_element(v.begin(),v.end());
	cout<<"Max"<<max;
	
	vector<int > f(6,0);
	for(vector<int >::iterator it=v.begin();it!=v.end();it++)
		f[*it]+=1;
	int maxfreq=*max_element(f.begin(),f.end());
	cout<<"max Frequency "<<maxfreq;
	
	sort(v.begin(),v.end());
	for(int i=0;i<6;i++)
		if(f[i]==maxfreq)
		{
			cout<<"\nId="<<i;
			break;
		}
	return 0;
}

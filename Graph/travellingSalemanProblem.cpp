#include<iostream>
using namespace std;
int n=4;
int dis[10][10]={
				{0,20,42,25},
				{20,0,30,34},
				{42,30,0,10},
				{25,34,10,0},
};
int visited_all=(1<<n)-1;
int tsp(int mask,int pos){
	if(mask==visited_all){
		return dis[pos][0];
	}
	int ans=INT_MIN;
	for(int city=0;city<n;city++){
		if((mask&(1<<city))==0){
			int newAns = dist[pos][city]+tsp(mask|(1<<city),city);
			ans=min(ans,newAns);
		}
	}
	return ans;
}
int main(){
	cout<<"Travelling Saleman Distance is"<<tsp(1,0);
	return 0;
}

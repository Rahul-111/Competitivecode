#include<iostream>
#include<cmath>
using namespace std;
int main(){
	int n;
	cin>>n;
	while(n--){
		
	int a,b;
	cin>>a>>b;
	
	int prime[b+1];
	for(int i=0;i<=b;i++)
		prime[i]=1;
	for(int i=0;i<b;i++)
		cout<<prime[i]<<" ";
	cout<<endl;
	prime[0]=0;
	prime[1]=0;
	for(int i=2;i<=b;i++){
		if(prime[i]==1){
			for(int j=2;i*j<=b;j++){
				prime[i*j]=0;
			}
		}	
	}
	int total=0;
	for(int i=1;i<=b;i++){
		if(prime[i]==1){
			cout<<i<<endl;
			total++;
		}
	}
	cout<<endl;
	int al=0;
	for(int i=1;i<a;i++){
		if(prime[i]==1){
			cout<<i<<endl;
			al++;
		}
	}
	cout<<"Number of two divisor "<<total-al<<endl;
	}	
	return 0;
}

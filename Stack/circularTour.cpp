#include<bits/stdc++.h>
using namespace std;
struct petrolPump
{
    int petrol;
    int distance;
};
int tour(petrolPump [],int );
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        petrolPump p[n];
        for(int i=0;i<n;i++)
            cin>>p[i].petrol>>p[i].distance;
        cout<<tour(p,n)<<endl;
    }
}
int tour(petrolPump p[],int n)
   int pt =0; int temp=0;
   for(int i=0; i<n; i++){
       pt+=p[i].petrol-p[i].distance;
       if(pt<0){
          temp = i+1;
          pt =0;
       }
   	}
   		if(temp >=n){
       	return -1;
   		}
   		else{
       		for(int i=0;i<temp;i++){
           		pt+=p[i].petrol-p[i].distance;
           		if(pt<0)
            		return -1;
       		}
       	return temp;
   		}
}

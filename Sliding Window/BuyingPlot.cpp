//Find a subarray of min length whose sum is k
#include<bits/stdc++.h>
using namespace std;
void bruteForce(int A[],int sum,int n){
	int flag=0;
	for(int size=1;size<=n&&flag==0;size++){
		for(int i=0;i<n-size &&flag==0;i++){
			int windowsum=0;
			for(int j=i;j<size+i;j++){
				windowsum+=A[j];
				if(sum==windowsum){
					cout<<"minimum size ="<<size<<endl;
					flag=1;		
					break;
				}
			}	
		}
	}
}
void slidingWindow(int A[],int sum,int n){
	int size,runningSum;
	int i=0,j=0;
	size=n;
	runningSum=A[0];
	cout<<"sliding Window"<<endl;
	while(j<n){
		if(runningSum < sum){
			j++;
			runningSum=runningSum + A[j];
		}
		if(runningSum > sum){
			runningSum=runningSum-A[i];
			i++;
		}
		if(runningSum==sum){
			size=min(j-i+1,size);
			runningSum=runningSum-A[i];
			i++;
		}
	}
	cout<<size<<endl;
}
int main(){
	int A[]={1,3,2,1,4,1,3,2,1,1,2};
	int sum=10;
	int n=sizeof(A)/sizeof(A[0]);
	//brute Force
	bruteForce(A,sum,n);
	cout<<"Using Sliding Window protocol"<<endl;
	slidingWindow(A,sum,n);
	return 0;
}

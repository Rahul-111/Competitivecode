#include <iostream>
#include<math.h>
using namespace std;
int OneWrong(int a, int b){
    int c,sum=0,r,i=0;
	c=a-b;
	//scout<<c<<"\n";
	while(c>0){
		r=c%10;
		c=c/10;
	    if(c==0){
		    sum+=pow(10,i)*(1 + int(10*rand()/(RAND_MAX + 1.0)));
	    }
	    else{
		    sum+=pow(10,i)*r;
	    }
	    i++;
	}
	    //cout<<sum;
	    return sum;
}
int main() {
	// your code goes here
    int a,b,x;
    cin>>a>>b;
    x=OneWrong(a,b);
	cout<<x;
	return 0;
}

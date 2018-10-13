#include<iostream>
using namespace std;
int power(int a, int n)
{
	if(n==0)
		return 1;
	else{
		int long r= power(a,n/2);
		if(n%2==0)
			return r*r;
		else
			return r*r*a;
	}		
}

int Power(int a, int N, int M) {
        if (N == 0) {
            return 1;
        } else {
            int long R = Power(a, N / 2, M);
            if (N % 2 == 0) {
                return (R * R) % M;
            } else {
                return (R * R * a) % M;
            }
    }
}
int main()
{
	int a=5;
	int n=6;
	cout<<power(5,6);
}

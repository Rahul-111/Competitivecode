#include<bits/stdc++.h>
#include <boost/multiprecision/cpp_int.hpp>
using namespace std;
// int FindLCM (int a, int b) 
// { 
//     return (a * b) / __gcd(a, b); 
// } 
int main(){
    int t;
    cin>>t;
    
    while(t--){
        using boost::multiprecision::cpp_int;
        cpp_int n,a,b,k;
        cin>>n>>a>>b>>k;
        cpp_int da,db,dab,ans,lcm;
		lcm= (a*b)/ __gcd(a,b);
		da = n/a;
		db = n/b;
		dab = n/lcm;
		ans = da + db -2*dab;
        if(ans >= k )
            cout<<"Win"<<endl;
        else if (ans < k)
            cout<<"Lose"<<endl;
    }
    return 0;
}

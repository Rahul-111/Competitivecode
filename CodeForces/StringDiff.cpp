        #include<bits/stdc++.h>
        using namespace std;
        int main(){
          string x,y;
          cin>>x>>y;
          for(int i=0;i<x.size();i++){
            if(x[i]<'a'){
              x[i]=x[i]+32;
            }
            if(y[i]<'a'){
              y[i]=y[i]+32;
            }
          }
          int i;
          for(i=0;i<x.size();i++){
            if(x[i]==y[i])
              continue;
            else if(x[i]<y[i]){
              cout<<"-1"<<endl;
              break;
            }else{
              cout<<"1"<<endl;
              break;
            }
          }
          if(i==x.size())
            cout<<"0"<<endl;
          return 0;
        }

#include <iostream>
#include<conio.h>

using namespace std;
int m,n,w[10],x[10];
void sum_subset(int s,int k,int r)
{
    x[k]=1;
    if(s+w[k]==m)
    {
        cout<<"if";
        for(int i=1;i<=n;i++)
        {
            cout<<"inside for";
            //cout<<x[i]<<"\t";
        }
        cout<<"\n";

    }
    else{
            cout<<"else";
        if((s+w[k]+w[k+1])<=m)
        {
            sum_subset(s+w[k],k+1,r-w[k]);
        }

    }
    if(((s+r-w[k])>=m) && ((s+w[k+1])<=m))
    {
        x[k]=0;
        sum_subset(s,k+1,r-w[k]);
    }
}

int main()
{
    int n;
    cout<<"Enter the number of values:\t";
    cin>>n;
    cout<<"Enter the sum:\t";
    cin>>m;
    cout<<"Enter the values:";
    int i;
    for(i=1;i<=n;i++)
    {
        cin>>w[i];
    }
    /*for(i=1;i<=n;i++)
    {
        cout<<w[i];
    }*/

    int r;
    r=0;
    for(i=1;i<=n;i++)
    {
        r+=w[i];
    }
    sum_subset(0,1,r);
    cout<<"\ncomplete";
    return 0;
}


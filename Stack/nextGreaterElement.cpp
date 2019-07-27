using namespace std;

int main()
{
    long long int n,t;
    cin>>t;
    while(t--)
    {
        
        cin>>n;
        long long int arr[n];
        long long int ans[n];
        
        for(int i=0;i<n;i++)
            cin>>arr[i];
            
        stack<long long int>S;
        
        for(int i=n-1;i>=0;i--)
        {
            while(!S.empty() and arr[i]>=S.top())
                S.pop();
            ans[i] = S.empty() ? -1 : S.top();
            
            S.push(arr[i]);
        }
        for(int i=0;i<n;i++)
            cout<<ans[i]<<" ";
        cout<<endl;
    }
}


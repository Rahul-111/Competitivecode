class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int **ans;
        int m=grid.size();
        int n=grid[0].size();
        // cout<<"m ="<<m<<" n = "<<n<<endl; 
        ans = new int*[m];
        for(int i=0;i<m;i++){
            ans[i] = new int[n];
            for(int j=0;j<n;j++)
                ans[i][j]=0;
        }
        
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                ans[i][j] = grid[i][j];
                // cout<<ans[i][j]<<" ";
                // cout<<"yes"<<i<<" "<<j<<"   ";
                if(i>0 && j>0){
                    ans[i][j] += min(ans[i-1][j],ans[i][j-1]);
                }
                else if(i>0){
                    ans[i][j] += ans[i-1][j];
                }
                else if(j>0){
                    ans[i][j] += ans[i][j-1];
                }
            }
        }
        int count;
        count = ans[m-1][n-1];
        return count;
    }
};

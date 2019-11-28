class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        
        for(int i=0;i<n-2;i++){
            int l=i+1;
            int r=n-1;
            
            while(l<r){
                if(nums[l]+nums[r]+nums[i]==0){
                    vector<int> temp;
                    temp.push_back(nums[i]);
                    temp.push_back(nums[l]);
                    temp.push_back(nums[r]);
                    ans.push_back(temp);
                    
                    int leftValue = nums[l];
                    while(l<r && leftValue==nums[l]){
                        ++l;
                    }
                    
                    int rightValue = nums[r];
                    while(r>l && rightValue==nums[r]){
                        --r;
                    }
                    
                }else if(nums[l]+nums[r]+nums[i] > 0){
                    r--;
                }else{
                    l++;
                }
                
            }
            while(i+2<n && nums[i]==nums[i+1]){
                i++;
            }
        }
        return ans;
    }
};

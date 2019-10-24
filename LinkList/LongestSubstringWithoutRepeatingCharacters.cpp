class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l=0,r=0;
        int ans=0;
        unordered_set<int> hash;
        while(r<s.size()){
            //is not present
            if(hash.find(s[r])==hash.end()){
                hash.insert(s[r]);   
                ans=max(ans,r-l+1);
                r++;
            }else{
                hash.erase(s[l]);
                l++;
            }
            
        }
        return ans;
    }
};

class Solution {
public:
    int romanToInt(string s) {
        unordered_map<string,int> Map;
        Map["I"]=1;
        Map["IV"]=4;
        Map["V"]=5;
        Map["IX"]=9;
        Map["X"]=10;
        Map["XL"]=40;
        Map["L"]=50;
        Map["XC"]=90;
        Map["C"]=100;
        Map["CD"]=400;
        Map["D"]=500;
        Map["CM"]=900;
        Map["M"]=1000;
        int n=s.size();
        int ans=0;
        for(int i=0;i<n;i++){
            int j=i+1;
            if(j<n){
                if(Map.find(s.substr(i,2))!=Map.end()){
                    ans+=Map[s.substr(i,2)];
                    i++;
                }
                else{
                // string z="";
                // z+=s[i];
                ans+=Map[s.substr(i,1)];
                }
            }
            else{
                // string y="";
                // y+=s[i];
                ans+=Map[s.substr(i,1)];
            }
        }
        return ans;
    }
};

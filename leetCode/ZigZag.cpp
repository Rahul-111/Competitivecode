class Solution {
public:
    string convert(string s, int numRows) {
     
        //corner case
        if(numRows==1)
            return s;
        vector<string> v(min(numRows,int(s.size())));
        int curRow=0;
        bool goingDown=false;
        
        for(int i=0;i<s.size();i++){
            v[curRow] +=s[i];
            if(curRow == 0 || curRow == numRows-1)
                goingDown=!goingDown;
            curRow +=goingDown?1:-1;
        }
        
        string res="";
        for(int i=0;i<v.size();i++){
            for(int j=0;j<v[i].size();j++){
                res+=v[i][j];
            }
        }
        return res;
    }
};

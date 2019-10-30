class Solution {
public:
    int myAtoi(string str) {
        if(str.size()==0)
            return 0;
        //skip extra inital whitespace
        int i=0,n=str.size(),sign=1;
        while(i<n && str[i]==' ')   //for string "    42"
            i++;
        if(i == n)
            return 0;
        if(str[i]=='-' || str[i]=='+'){
            sign= (str[i]=='+')?1:-1;
            i++;
        }
        long long int ans=0;
        while(i<n && str[i]>='0' && str[i]<='9'){
            ans=ans*10+(str[i]-'0');
            if(sign*ans<=INT_MIN || sign*ans>=INT_MAX){
                return sign ==1?INT_MAX:INT_MIN;
            }
            i++;
        }

        return sign*ans;
    }
};

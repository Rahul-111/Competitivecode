class Solution {
public:
    string intToRoman(int num) {
        unordered_map<int,string> Map;
        Map[1]="I";
        Map[4]="IV";
        Map[5]="V";
        Map[9]="IX";
        Map[10]="X";
        Map[40]="XL";
        Map[50]="L";
        Map[90]="XC";
        Map[100]="C";
        Map[400]="CD";
        Map[500]="D";
        Map[900]="CM";
        Map[1000]="M";
        string res="";
        vector<string> ans;
        int arr[13]={1000,900,500,400,100,90,50,40,10,9,5,4,1};
        while(num>0){
            
            for(int i=0;i<13;i++){
                if(arr[i] > num)
                    continue;
                // for complete division
                if(num%arr[i]==0){
                    for(int t=0;t<num/arr[i];t++){
                        ans.push_back(Map[arr[i]]);
                        res+=Map[arr[i]];
                    }
                    num=num%arr[i];
                    break;
                }
                else{
                    int x = num/arr[i];
                    num = num%arr[i];
                    for(int t=0;t<x;t++){
                        res+=Map[arr[i]];
                    }
                    break;
                }
            }
        }
        return res;
    }
};
class Solution {
public:
    string intToRoman(int num) {
    unordered_map<int,string> Map;
    string s[13]={"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};
    int v[13]={1000,900,500,400,100,90,50,40,10,9,5,4,1};
    // Map[1]="I";
    // Map[4]="IV";
    // Map[5]="V";
    // Map[9]="IX";
    // Map[10]="X";
    // Map[40]="XL";
    // Map[50]="L";
    // Map[90]="XC";
    // Map[100]="C";
    // Map[400]="CD";
    // Map[500]="D";
    // Map[900]="CM";
    // Map[1000]="M";
    string res="";
        int i=0;
        while(num > 0){
            if(num-v[i]>=0){
                res += s[i];
                num=num-v[i];
            }else{
                i++;
            }
        }
        return res;
    }
};

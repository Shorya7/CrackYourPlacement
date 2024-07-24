class Solution {
public:
    string removeKdigits(string num, int k) {
        string s;s+=num[0];
        for(int i=1;i<num.length();i++){
            if(!s.empty()&&num[i]<s.back()&&k>0){
                s.pop_back();
                i--;k--;
            }
            else  s+=num[i];
        }
        while(k>0&&!s.empty()){
            s.pop_back();k--;
        }
        while(s[0]=='0')
        s.erase(s.begin());
        if(s=="")s+="0";
        return s;
    }
};
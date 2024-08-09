class Solution {
public:
    int calculate(string s) {
        int ans=0,r=0,cur=0;
        char op='+';
        s+="!!";
        for(char c:s){
            if(c==' ')continue;
            else if(isdigit(c))
            cur=cur*10+(c-'0');
            else{
                if(op=='*')
                r*=cur;
                else if(op=='/')
                r/=cur;
                else{
                    ans+=r;
                    r=op=='+'?cur:-cur;
                }
                op=c;
                cur=0;
            }
        }
        return ans;
    }
};
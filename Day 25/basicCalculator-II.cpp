// SOLUTION 1

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


//---------------------------------------------------------------------------------------------------------------------------
//  Solution 2 (Using STACK)

class Solution {
public:
    int calculate(string s) {
        s+='+';
        stack<int>st;
        char op='+';
        int ans=0,cur=0;
        for(char c:s){
            if(c==' ')continue;
            if(isdigit(c))
            cur=cur*10+(c-'0');
            else{
                if(op=='+')st.push(cur);
                else if(op=='-')st.push(-cur);
                else if(op=='*'){
                    int n=st.top();
                    st.pop();
                    st.push(n*cur);
                }
                else{
                    int n=st.top();
                    st.pop();
                    st.push(n/cur);
                }
                cur=0;
                op=c;
            }
        }
        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }
        return ans;
    }
};
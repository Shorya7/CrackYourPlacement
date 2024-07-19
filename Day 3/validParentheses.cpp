class Solution {
public:
    bool isValid(string s) {
        stack<char>st;
        for(char c:s){
            if(c=='('||c=='{'||c=='[')
            st.push(c);
            else{
                if(st.empty())return false;
                int x=st.top();
                if((c==')'&&x!='(')||(c=='}'&&x!='{')||(c==']'&&x!='['))
                return false;
                st.pop();
            }
        }
        return st.empty();
    }
};
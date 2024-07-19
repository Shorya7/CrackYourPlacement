class Solution {
public:
    string reverseWords(string s) {
        stack<string>st;
        string t;
        for(int i=0;i<=s.size();i++){
            if(s[i]==' '||i==s.size()){
                st.push(t);
                t="";
            }
            else t+=s[i];
        }
        while(!st.empty()){
            t+=st.top();
            t+=" ";
            st.pop();
        }
       int c=0;
        string ans;
        for(int i=0;i<t.size();i++){
            if(t[i]==' '&&c!=1)continue;
            if(t[i]==' '&&c==1){
                ans+=' ';c=0;
            }
            else{
                ans+=t[i];
                c=1;
            }
        }
        ans.erase(ans.end()-1,ans.end());
        return ans;
    }
    
};
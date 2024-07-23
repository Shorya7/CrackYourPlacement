class Solution {
public:
    string simplifyPath(string path) {
        stack<string>s;
        string ans;
        for(int i=0;i<path.size();i++){
            if(path[i]=='/')continue;
            string x;
            while(i<path.size()&&path[i]!='/'){
                x+=path[i++];
            }
            if(x==".")continue;
            else if(x==".."){
                if(!s.empty())s.pop();
            }
            else s.push(x);
        }
        if(s.empty())return "/";
        while(!s.empty()){
            ans="/"+s.top()+ans;
            s.pop();
        }
        
        return ans;
    }
};
// SOLUTION 1

class Solution {
public:
    string removeDuplicates(string s, int k) {
        vector<pair<char,int>>v;
        for(char c:s){
            if(!v.empty()&&v.back().first==c)
            v.back().second++;
            else v.push_back({c,1});
            if(v.back().second==k)
            v.pop_back();
        }
        string ans;
        for(auto i:v)
        ans.append(i.second,i.first);
        return ans;
    }
};

//----------------------------------------------------------------------------------------------------------------------------
// SOLUTION 2 (Using STACK)

class Solution {
public:
    string removeDuplicates(string str, int k) {
        stack<pair<char,int>>s;
        for(char c:str){
            if(!s.empty()&&s.top().first==c){
                auto i=s.top();
                s.pop();
                if(i.second<k-1)s.push({i.first,i.second+1});
            }
            else s.push({c,1});
        }
        string ans;
        while(!s.empty()){
            while(s.top().second--)
            ans+=s.top().first;
            s.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
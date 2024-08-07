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
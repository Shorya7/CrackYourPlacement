class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& v) {
        vector<int>ans(v.size(),0);
        stack<int>s;
        for(int i=0;i<v.size();i++){
            while(!s.empty()&&v[i]>v[s.top()]){
                int ind=s.top();
                s.pop();
                ans[ind]=i-ind;
            }
            s.push(i);
        }
        return ans;
    }
};
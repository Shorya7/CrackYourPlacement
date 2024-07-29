class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int>m;
        int s=0,ans=0;
        m[s]=1;
        for(auto i:nums){
            s+=i;
            int x=s-k;
            if(m.find(x)!=m.end())
            ans+=m[x];
            m[s]++;
        }
        return ans;
    }
};
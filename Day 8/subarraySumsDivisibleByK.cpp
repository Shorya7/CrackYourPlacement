class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int,int>pm={{0,1}};
        int s=0,ans=0;
        for(int i=0;i<nums.size();i++){
            s=(s+nums[i])%k;
            if(s<0)s+=k;
            if(pm.find(s)!=pm.end()){
                ans+=pm[s];
                pm[s]++;
            }
            else pm[s]=1;
        }
        return ans;
    }
};
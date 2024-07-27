class Solution {
public:
    int coinChange(vector<int>& v, int amt) {
        vector<int>dp(amt+1,INT_MAX);
        dp[0]=0;
        for(int i=1;i<=amt;i++){
            for(int j=0;j<v.size();j++){
                if(i-v[j]>=0&&dp[i-v[j]]!=INT_MAX)
                dp[i]=min(dp[i],1+dp[i-v[j]]);
            }
        }
        if(dp[amt]==INT_MAX)return -1;
        return dp[amt];
    }
};
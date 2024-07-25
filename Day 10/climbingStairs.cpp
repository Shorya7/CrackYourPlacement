class Solution {
public:
    int climbStairs(int n) {
        // vector<int>dp(n+1);
        int p1=1,p2=1;
        for(int i=2;i<=n;i++){
            int c=p1+p2;
            p2=p1;
            p1=c;
        }
        return p1;
    }
    // int solve(int n, vector<int>&dp){
    //     if(n<=1)return 1;
    //     if(dp[n]!=-1)return dp[n];
    //     dp[n]=solve(n-1,dp)+solve(n-2,dp);
    //     return dp[n];
    // }
};
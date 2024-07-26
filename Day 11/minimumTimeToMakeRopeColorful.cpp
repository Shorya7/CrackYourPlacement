class Solution {
public:
    int minCost(string s, vector<int>&v) {
        int ans=0,n=s.size(),i=1;
        while(i<n){
            if(s[i]!=s[i-1])i++;
            else{
                int sm=v[i-1],m=v[i-1];
                while(s[i]==s[i-1]){
                    sm+=v[i];
                    m=max(v[i],m);
                    i++;
                }
                ans+=(sm-m);
            }
        }
        return ans;
    }
};
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        double p=1,ans=LLONG_MIN,l=1;
        for(int i=0;i<nums.size();i++){
            p*=nums[i];
            l*=nums[nums.size()-i-1];
            ans=max({ans,p,l});
            if(p==0)p=1;
            if(l==0)l=1;
        }
        return (int)ans;
    }
};
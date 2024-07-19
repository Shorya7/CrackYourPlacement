class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int m=nums[nums.size()/2],ans=0;
        for(auto i:nums)
        ans+=(abs(m-i));
        return ans;
    }
};
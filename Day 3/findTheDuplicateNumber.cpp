class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        vector<int> f(nums.size(),0);
        for(int i=0;i<nums.size();i++){
            f[nums[i]]++;
            if(f[nums[i]]>1)
            return nums[i];
        }
        return 0;
    }
};
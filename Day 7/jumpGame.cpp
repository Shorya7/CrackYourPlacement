class Solution {
public:
    bool canJump(vector<int>& nums) {
        if(nums.size()==1)return true;
        int req=1;
        for(int i=nums.size()-2;i>=0;i--){
            if(nums[i]>=req)req=1;
            else req++;
        }
        return req==1;
    }
};
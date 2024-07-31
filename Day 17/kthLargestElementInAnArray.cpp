class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int,vector<int>, greater<int>>m;
        for(int i=0;i<k;i++)m.push(nums[i]);
        for(int i=k;i<nums.size();i++){
            if(nums[i]>m.top()){
                m.pop();
                m.push(nums[i]);
            }
        }
        return m.top();
    }
};
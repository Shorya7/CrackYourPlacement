class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        set<vector<int>>s;
        for(int i=0;i<nums.size();i++){
            int j=i+1,k=nums.size()-1,sm=0;
            while(j<k){
                sm=nums[i]+nums[j]+nums[k];
                if(sm==0){
                    s.insert({nums[i],nums[j],nums[k]});
                    j++;k--;
                }
                else if(sm>0)k--;
                else j++;
            }
        }
        vector<vector<int>>ans;
        for(auto i:s){
            ans.push_back(i);
        }
        return ans;
    }
};
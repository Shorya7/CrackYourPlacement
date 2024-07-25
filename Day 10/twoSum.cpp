class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int>v(2);
        vector<pair<int,int>>c(nums.size());
        for(int i=0;i<nums.size();i++){
            c[i]={nums[i],i};
        }
        sort(c.begin(),c.end());
        int l=0,r=nums.size()-1;
        while(l<r){
            if(c[l].first+c[r].first>target)r--;
            if(c[l].first+c[r].first<target)l++;
            if(c[l].first+c[r].first==target){
                v[0]=c[l].second;v[1]=c[r].second;
                return v;
            }
        }
        return v;
    }
};
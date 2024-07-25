class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        int ans=0,e=INT_MIN;
        for(auto i:intervals){
            if(e>i[0]){
                ans++;
                e=min(e,i[1]);
            }
            else e=i[1];
        }
        return ans;
    }
};
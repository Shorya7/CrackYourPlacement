class Solution {
public:
    int maxArea(vector<int>& h) {
        int l=0,r=h.size()-1,ans=0;
        while(l<r){
            int c=min(h[l],h[r])*(r-l);
            ans=max(ans,c);
            if(h[l]>h[r])r--;
            else l++;
        }
        return ans;
    }
};
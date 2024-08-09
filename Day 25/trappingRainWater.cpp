class Solution {
public:
    int trap(vector<int>& height) {
        int i=0,j=height.size()-1,l=height[0],r=height[j],s=0;
        while(i<j){
            if(l<=r){
            s+=(l-height[i]);i++;
            l=max(l,height[i]);}
            else{
                s+=(r-height[j]);
                j--;r=max(r,height[j]);
            }
        }
        return  s;
    }
};
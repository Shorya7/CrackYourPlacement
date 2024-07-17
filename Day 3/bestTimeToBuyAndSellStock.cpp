class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int b=prices[0],ans=0;
        for(int i:prices){
            if(b>i)b=i;
            else if(i-b>ans)
            ans=i-b;
        }
        return ans;
    }
};
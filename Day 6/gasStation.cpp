class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int sg=0,sc=0,ans,c=0;
        for(int i=0;i<gas.size();i++){
            sg+=gas[i];
            sc+=cost[i];
        }
        if(sc>sg)return -1;
        for(int i=0;i<gas.size();i++){
            c=gas[i]-cost[i];
            if(c<0){
                c=0;
                ans=i+1;
            }
        }
        return ans;
    }
};
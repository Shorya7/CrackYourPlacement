// SOLUTION (MIN HEAP)

class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        priority_queue<int,vector<int>,greater<int>>pq;
        for(int i=1;i<heights.size();i++){
            int d=heights[i]-heights[i-1];
            if(d>0)pq.push(d);
            if(pq.size()>ladders){
                if(pq.top()<=bricks){
                bricks-=pq.top();
                pq.pop();
                }
                else return i-1;
            }
        }
        return heights.size()-1;
    }
};
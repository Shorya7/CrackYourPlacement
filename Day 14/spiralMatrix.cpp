class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m=matrix.size(),n=matrix[0].size(),r=0,c=-1,x=1;
        vector<int>ans;
        while(m>0&&n>0){
            for(int i=0;i<n;i++){
                c+=x;
                ans.push_back(matrix[r][c]);
            }
            m--;
            for(int i=0;i<m;i++){
                r+=x;
                ans.push_back(matrix[r][c]);
            }
            n--;
            x*=-1;
        }
        return ans;

    }
};
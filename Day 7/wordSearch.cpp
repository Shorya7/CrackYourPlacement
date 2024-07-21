class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(bt(board,word,i,j,0))
                return true;
            }
        }
        return false;
    }
    bool bt(vector<vector<char>>&v, string w,int i, int j, int k){
        if(k==w.length())
        return true;
        if(i<0||i>=v.size()||j<0||j>=v[0].size()||v[i][j]!=w[k])
        return false;
        char c=v[i][j];
        v[i][j]=0;
        if(bt(v,w,i-1,j,k+1)||bt(v,w,i+1,j,k+1)||bt(v,w,i,j+1,k+1)||bt(v,w,i,j-1,k+1))
        return true;
        v[i][j]=c;
        return false;
    }
};
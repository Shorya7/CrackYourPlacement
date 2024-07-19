class Solution {
public:
bool check(int i,int j, string s){
    while(i<=j){
        if(s[i]!=s[j])return false;
        i++;j--;
    }
    return true;
}
    bool validPalindrome(string s) {
        int i=0,j=s.size()-1;
        while(i<=j){
            if(s[i]!=s[j]){
                return check(i,j-1,s)||check(i+1,j,s);
            }
            else{
                i++;
                j--;
            }
        }
        return true;
    }
};
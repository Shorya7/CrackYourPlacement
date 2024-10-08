class Solution {
public:
    string convertToTitle(int n) {
        string ans;
        while (n) {
            n--;
            int r = n % 26;
            ans = char(r + 'A') + ans;
            n /= 26;
        }
        return ans;
    }
};
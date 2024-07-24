class Solution {
public:
    string solve(string s) {
        string x;
        for (char c : s) {
            if (c != '#')
                x.push_back(c);
            else {
                if (!x.empty())
                    x.pop_back();
            }
        }
        return x;
    }
    bool backspaceCompare(string s, string t) {
        string sn=solve(s);
        string tn=solve(t);
        return sn==tn;
    }
};
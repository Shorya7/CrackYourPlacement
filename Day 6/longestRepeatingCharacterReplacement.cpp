class Solution {
public:
    int characterReplacement(string s, int k) {
        int ans=0,n=s.size();
        for(char c='A';c<='Z';c++){
            int i=0,j=0,ct=0;
            while(j<n){
                if(s[j]==c)j++;
                else if(ct<k)ct++,j++;
                else if(s[i]==c)i++;
                else i++,ct--;
                ans=max(ans,j-i);
            }
        }
        return ans;
    }
};
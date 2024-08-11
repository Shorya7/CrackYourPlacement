class Solution {
public:
    int minDeletions(string s) {
        vector<int>v(26,0);
        for(char c:s)v[c-'a']++;
        sort(v.begin(),v.end());
        int ans=0,i=24, m=v[25],l;
        // for(int i:v)cout<<i<<" ";
        while(i>=0&&m>=1){

            l=v[i];
            int x=v[i]+1-m;

            if(x<0)m=v[i];
            else{
                ans+=x;
                m--;
            }
            i--;
        }

        while(l>0&&i>=0){
            ans+=v[i];
            i--;
        }
        
        return ans;
    }
};
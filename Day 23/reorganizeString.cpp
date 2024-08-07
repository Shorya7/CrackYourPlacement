// SOLUTION 1

class Solution {
public:
    string reorganizeString(string s) {
        if(s.size()==1)return s;
        vector<int>v(26,0);
        for(char c:s)v[c-'a']++;
        int c=ceil(s.size()/2.0);
        string ans;
        for(int i=0;i<26;i++){
            if(v[i]>c)return "";
        }
        int x=1,sk=-1;
        while(x){
            int lg=0,ind=-1;
            for(int i=0;i<26;i++){
                if(v[i]>lg&&i!=sk){
                    lg=v[i];
                    ind=i;
                }
            }
            if(lg==0)break;
            ans+=ind+'a';
            v[ind]--;
            sk=ind;
        }
        return ans;

    }
};


//----------------------------------------------------------------------------------------------------------------------------
// SOLUTION 2 (MAX HEAP)

class Solution {
public:
    string reorganizeString(string s) {
        map<char,int>m;
        for(char c:s)m[c]++;
        priority_queue<pair<int,char>>pq;
        for(auto i:m)pq.push({i.second,i.first});
        string ans;
        while(pq.size()>1){
            auto t1=pq.top();
            pq.pop();
            auto t2=pq.top();
            pq.pop();
            ans+=t1.second;
            ans+=t2.second;
            t1.first--;
            t2.first--;
            if(t1.first>0)
            pq.push(t1);
            if(t2.first>0)
            pq.push(t2);
        }
        if(!pq.empty()){
            auto t=pq.top();
            if(t.first>1)return "";
            ans+=t.second;
        }
        return ans;
    }
};
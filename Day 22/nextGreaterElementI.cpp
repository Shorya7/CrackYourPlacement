// SOLUTION 1 (Brute Force)

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int>ans(nums1.size(),-1);
        for(int i=0;i<nums1.size();i++){
            int j=0;
            while(nums2[j]!=nums1[i])
            j++;
            for(int k=j+1;k<nums2.size();k++){
                if(nums2[k]>nums1[i]){
                    ans[i]=nums2[k];
                    break;
                }
            }
        }
        return ans;
    }
};

//-------------------------------------------------------------------------------------------------------------------------
// SOLUTION -2 (Using STACK)

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int>ans;
        stack<int>s;
        unordered_map<int,int>m;
        for(int i=nums2.size()-1;i>=0;i--){
            while(!s.empty()&&s.top()<nums2[i])
            s.pop();
            if(s.empty())
            m[nums2[i]]=-1;
            else m[nums2[i]]=s.top();
            s.push(nums2[i]);
        }
        for(int i=0;i<nums1.size();i++)
        ans.push_back(m[nums1[i]]);
        return ans;
    }
};
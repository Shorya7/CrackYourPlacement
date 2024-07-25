//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution 
{
    public:
    //Function to find the minimum number of swaps required to sort the array. 
	int minSwaps(vector<int>&nums)
	{
	    // Code here
	    unordered_map<int,int>m;
	    vector<int>v(nums.begin(),nums.end());
	    sort(v.begin(),v.end());
	    for(int i=0;i<v.size();i++)
	    m[v[i]]=i;
	    int ans=0;
	    for(int i=0;i<v.size();i++){
	        if(m[nums[i]]!=i){
	            swap(nums[i],nums[m[nums[i]]]);
	            ans++;
	            i--;
	        }
	    }
	    return ans;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<int>nums(n);
		for(int i = 0; i < n; i++)
			cin >> nums[i];
		Solution obj;
		int ans = obj.minSwaps(nums);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends
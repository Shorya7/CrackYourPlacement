#include "bits/stdc++.h"
bool isPoss(vector<int> &stalls,int mid, int k){
    int last=stalls[0], c=1;
    for(int i=1;i<stalls.size();i++){
        if((stalls[i]-last)>=mid){
            last=stalls[i];c++;
        }
        if(c==k)return true;
    }
    return false;
}
int aggressiveCows(vector<int> &stalls, int k)
{
    //    Write your code here.
    sort(stalls.begin(),stalls.end());
    int l=1,h=stalls[stalls.size()-1]-stalls[0];
    while(l<=h){
        int mid=(l+h)/2;
        if(isPoss(stalls,mid,k))
        l=mid+1;
        else h=mid-1;
    }
    return h;
}

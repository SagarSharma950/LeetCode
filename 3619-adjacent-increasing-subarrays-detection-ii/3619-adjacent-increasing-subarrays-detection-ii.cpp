class Solution {
public:
    int maxIncreasingSubarrays(vector<int>&nm) {
        int ans=0,i,n=nm.size(),k,save=1,c=1;
        for(i=1;i<n;i++){
            if(nm[i]>nm[i-1])
                c++;
            else {
               ans=max(ans,min(save,c));
               ans=max(ans,max(save/2,c/2));
               save=c;
               c=1;
            }
        }
        ans=max(ans,min(save,c));
        ans=max(ans,max(save/2,c/2));
        return ans;
    }
};
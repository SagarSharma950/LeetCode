class Solution {
public:
    int minimumOperationsToMakeKPeriodic(string wrd, int k) {
        unordered_map<string, int> mp;
        int i=0, rem=1;
        string st="";
        while(i<k){
            st+=wrd[i];
            i++;
        }
        mp[st]++;
        while(i<wrd.size()){
            string gt="";
            for(int j=i;j<i+k;j++) gt+=wrd[j];
            mp[gt]++;
            rem=max(rem,mp[gt]);
            i+=k;
        }
        return wrd.size()/k-rem;
    }
};
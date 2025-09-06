class Solution {
public:
long long solve(long long a, long long b)
{
    long long l=1, sm=0,s=1;
    while(b>=l)
    {
        long long r= l*4-1;
        int x=max(l, a), y=min(b, r);
        if(x<=y)
        sm+=(y-x+1)*s;
        s++;
        l=l*4;
    }
    return sm;
}
    long long minOperations(vector<vector<int>>& nm) {
        int n=nm.size();
        long long sm=0;
        for(auto a: nm)
        {
            long long r=solve(a[0], a[1]);
            sm+=(ceil(r/2.0));
        }
        return sm;
    }
};
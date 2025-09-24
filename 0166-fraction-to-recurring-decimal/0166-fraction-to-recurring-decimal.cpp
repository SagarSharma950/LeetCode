class Solution {
private:
    unordered_map<long long,int> dp;
    long long d;
    string s="";
    int solve(int idx,long long n){
        if(dp.find(n)!=dp.end()) {
           return dp[n];
        }
        dp[n]=idx;
        if(n<d){
            n*=10;
            s+='0';
            return solve(idx+1,n);
        }
        else{
            s+=((n/d)+'0');
            n-=((n/d)*d);
            n*=10;
            if(n==0) return -1;;
            return solve(idx+1,n);
        }
    }
public:
    string fractionToDecimal(int N, int D) {
        long long n=N;
        long long d=D;
        string ans="";
        if(n%d==0) return to_string(n/d);
        int isneg=0;
        if(n<0) isneg=1-isneg;
        if(d<0) isneg=1-isneg;
        n=abs(n);d=abs(d);
        if(isneg)  ans.push_back('-');
        this->d=d;
        int p=n/d;
        n-=(p*d);
        ans+=to_string(p);

        int idx=solve(0,n*10);
        ans+='.';
        if(idx==-1){
            ans+=s;
        }
        else{
            s.push_back(')');
            s.insert(s.begin()+idx,'(');
            ans+=s;
        }
        return ans;
    }
};
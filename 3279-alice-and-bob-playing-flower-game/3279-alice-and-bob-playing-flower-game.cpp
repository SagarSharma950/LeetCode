class Solution {
public:
    long long flowerGame(int n, int m) {
        long long odd=0,even=0;
        odd = (n+1)/2;  
        even=m/2; 
       long long odd1 = (m+1)/2;  
       long long  even1=n/2;     
        return odd1*even1 + odd*even;
    }
};
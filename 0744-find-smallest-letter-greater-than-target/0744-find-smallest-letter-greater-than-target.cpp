class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int n=letters.size();
        int l=0, h=n-1;
        while(l<=h){
            int m=l+(h-l)/2;
            if(letters[m]<=target) l=m+1;
            else h=m-1;
        }
        return letters[l%n];
    }
};
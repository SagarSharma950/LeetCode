class Solution {
public:
    int maxArea(vector<int>& height) {
        int ret=0,n=height.size();
        int left=0,right=n-1;
        while(left<right){
            ret=max((right-left)*min(height[left],height[right]),ret);
            if(height[left]<height[right]) left++;
            else right--;
        }
        return ret;
    }
};
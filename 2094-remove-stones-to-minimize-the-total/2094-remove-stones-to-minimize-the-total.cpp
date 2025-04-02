class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        priority_queue<int> maxHeap(piles.begin(),piles.end());
        while(k--){
            int maxi=maxHeap.top();
            maxHeap.pop();
            maxi-=maxi/2;
            maxHeap.push(maxi);
        }
        int sum=0;
        while(!maxHeap.empty()){
            sum+=maxHeap.top();
            maxHeap.pop();
        }
        return sum;
    }
};
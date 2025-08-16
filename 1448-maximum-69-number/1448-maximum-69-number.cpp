class Solution {
public:
    int maximum69Number (int num) {
        vector<int> arr;
        int temp=num;
        while(temp>0){
            arr.push_back(temp%10);
            temp/=10;
        }
        reverse(arr.begin(),arr.end());
        for(int i=0;i<arr.size();i++){
            if(arr[i]==6){
                arr[i]=9;
                break;
            }
        }
        int res=0;
        for(int i:arr){
            res=res*10+i;
        }
        return res;
    }
};
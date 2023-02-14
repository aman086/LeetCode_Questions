/*
Basic Approach which I have done is that I maintained two arrays
    one from starting and another one from ending
    if k = 3;
    then possible combinations are 
    start = 0 , end = 3
    start = 1 , end = 2
    start = 2 , end = 1
    start = 3 , end = 0
    that's how , I am checking for optimal Answer
    
*/
class Solution {
public:
    int maxScore(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> start(n+1 , 0);
        vector<int> last(n+1 , 0);
        for(int i=0;i<n;i++){
            start[i+1] = start[i] + nums[i]; 
        }
        for(int i=n-1;i>=0;i--){
            last[n-i] = last[n-i-1] + nums[i];
        }
        int finalAns = 0;
        for(int i=0;i<=k;i++)
        {
            finalAns = max(finalAns , start[i]+last[k-i]);
        }
        return finalAns;
    }
};

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        long int sum = 0;
        // we have to find a subArray whose sum is greater than or equal to target.
        int len = INT_MAX;
        int start=0;
        for(int i=0;i<n;i++){
            sum += nums[i];
            while(sum >= target && start<=i){
                len = min(len , i-start+1);
                sum -= nums[start];
                start++;
            }
        }
        if(len == INT_MAX) return 0;
        return len;
    }
};

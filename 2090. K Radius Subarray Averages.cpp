/*
  Here , we have to implement simple logic.
    we have to maintain a sliding window of (2*k + 1) size and initially put all elements to -1 and change the middle element of window with average
   till last
*/
class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> vtr(n , -1);
        int size = (2*k + 1);
        if(nums.size()<size) return vtr;
        long long int sum = 0;
        for(int i=0;i<size;i++){
            sum+=nums[i];
        }
        int start = 0;
        int end = size;
        vtr[k] = sum/size;
        while(end < n){
            sum += nums[end];
            sum -= nums[start];
            start++;
            end++;
            vtr[start+k] = sum/size;
        }
        return vtr;
    }
};

/*
Here , we have 3 possibilites :-
      (1). delete both indexes from start
      (2). delete both indexes from last
      (3). delete one from front and another from last
*/
class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int minIndex = 0;
        int maxIndex = 0;
        int mini = INT_MAX;
        int maxi = INT_MIN;
        int n = nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]<mini){
                mini = nums[i];
                minIndex = i;
            }
            if(nums[i] > maxi){
                maxi = nums[i];
                maxIndex = i;
            }
        }
        int operation = INT_MAX;
        int minima = min(minIndex , maxIndex);
        int maxima = max(maxIndex , minIndex);
        operation = min(operation , maxima+1);
        operation = min(operation , n - minima);
        operation = min(operation , minima + 1 + n - maxima);
        return operation;
    }
};

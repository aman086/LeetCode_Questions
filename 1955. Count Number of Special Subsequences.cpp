/*
        count_0 = ((count_0 * 2) + 1);
        count_1 = ((count_1 *2) + count_0);
        count_2 = ((count_2 *2) + count_1);
*/

class Solution {
public:
    int M = 1000000007;
    int countSpecialSubsequences(vector<int>& nums) {
        int n = nums.size();
        int count_0 = -1; // for [0,1,2] , here count_0 should give 0 that's why initialize it with -1;
        int count_1 = 0;
        int count_2 = 0;
        for(int i=0;i<n;i++){
            if(nums[i]==0){
                if(count_0 == -1)
                  count_0 = 0;
                count_0 = ((count_0 * 2)%M + 1)%M;
            }else if(nums[i]==1){
                if(count_0 != -1) // for this eg: [1,2,2,2]
                count_1 = ((count_1 * 2)%M + count_0)%M;
            }else{
                count_2 = ((count_2 * 2)%M + count_1)%M;
            }
        }
        return count_2;
    }
};

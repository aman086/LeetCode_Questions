/*
 Here , we have negative elements too , so if at any point sum < 0 then add k to it and continue 
like - 523. Continuous Subarray Sum.cpp
*/
class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int , int> mp;
        int cnt = 0;
        int n = nums.size();
        int sum = 0;
        mp[0] = 0;
        int sumModulo = 0;
        for(int i=0;i<n;i++){
            sum += nums[i];
            sumModulo = sum % k;
            if(sumModulo < 0)
              sumModulo += k;

            if(mp.find(sumModulo)!=mp.end()){
                mp[sumModulo]++;
                cnt += mp[sumModulo];
            }
            else 
               mp[sumModulo] = 0;
        }
        return cnt;
    }
};

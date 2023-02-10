/*
  Here , we have to find a subarray whose sum is divisible by k;
  so , first we work no modulo and at each index , we find prefix sum with modulo.
    if somewhere ,
        modulo is 3 and after sometime again it'll be 3 
    it means there is middle exist a modulo sum = 0 means a subarray exist with divisibility (k).
    and not choose consecutive because question restricted to >= 2 elements
    and also put 0 value index at -1.
    so that , if any zero occurs again , we can identify it

*/
class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int,int> mp;
        mp[0] = -1;
        int sum = 0;
        for(int i=0;i<n;i++){
            sum += nums[i];
            sum%=k;
            if(mp.find(sum)!=mp.end()){
                if((i-mp[sum] > 1)){
                    return true;
                }
            }else{
                mp[sum] = i;
            }
        }
        return false;
    }
};

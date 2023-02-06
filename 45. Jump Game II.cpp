class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        vector<int> check(n , INT_MAX);
        check[n-1] = 0;
        for(int j=n-2;j>=0;j--){
            if(nums[j]==0){
                // check[i] = INT_MAX;
                continue;
            }
            int k = j+1;
            while(k <= (j + nums[j])){
                if(k==n-1){
                    check[j] = 1;
                    break;
                }
                if(check[k]!=INT_MAX)
                check[j] = min(check[j] , check[k]+1);
                k++;
            }
        }
        return check[0];
    }
};

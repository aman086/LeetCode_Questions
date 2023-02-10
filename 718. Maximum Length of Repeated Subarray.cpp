/*
We have to use dp here , because at starting , I choose (set of vector, map of vector, vector of vector) but those will give me Time Limit Exceeded.
so , I use dp in such a way that,
     if(nums[i]==nums[j]) then dp[i][j] = dp[i-1][j-1] + 1;
                          else dp[i][j] = 0;
                    and in last go through all the values of dp and find out the maximum one. 
                    
       we do so  because it needs subArray, If it requires subSets then in the else part we change the code:
                                  if(nums[i]==nums[j]) then dp[i][j] = dp[i-1][j-1] + 1;
                                                    else dp[i][j] = max(dp[i-1][j] , dp[i][j-1]);
                                                    here , last one dp[n1][n2] gives us result.
                                                    
*/
class Solution {
public:

    
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        vector<vector<int>> dp(n1+1 , vector<int>(n2+1 , 0));
        for(int i=1;i<=n1;i++){
            for(int j=1;j<=n2;j++){
                if(nums1[i-1]==nums2[j-1])
                   dp[i][j] = dp[i-1][j-1] + 1;
                else
                  dp[i][j] = 0;   
            }
        }
        int maxi = INT_MIN;
        for(int i=0;i<=n1;i++){
            for(int j=0;j<=n2;j++){
                maxi = max(maxi , dp[i][j]);  
            }
        }
        return maxi;
    }
};

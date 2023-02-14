/*
I maintain a map<int,vector<int>> 

 where I store value according to the sum of indexes,
    diagonal means if sum of (i & j) of current Block is same then those blocks will be considered as diagonal
  sum = 1 =>>  (0,1) , (1,0)
  sum = 2 =>> (0,2) , (1,1) , (2,0)
  sum = 3 =>> (0,3) ,(1,2) , (2,1) , (3,0)
*/

class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        int n = nums.size();
        vector<int> finalAns;
        map<int , vector<int>> storeByIndex;
        for(int i=0;i<n;i++){
            // vector<int> current;
            for(int j=0;j<nums[i].size();j++){
                storeByIndex[i+j].push_back(nums[i][j]);
            }
        }
        for(auto it : storeByIndex){
            int sz = it.second.size();
            for(int i=sz-1;i>=0;i--)
              finalAns.push_back(it.second[i]);
        }
        return finalAns;
    }
};

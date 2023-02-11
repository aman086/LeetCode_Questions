/*
we simply use recursion here , nothing else. concept is simple
*/

class Solution {
public:

   void solve(int index , int n, int k , vector<int> current , vector<vector<int>>& result){
       if(index>n) return;
       current.push_back(index);
       if(current.size()==k){
           result.push_back(current);
           return;
       }
       for(int i=index+1;i<=n;i++)
            solve(i , n , k , current , result);
   }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> result;
        vector<int> current;
 
        for(int i=1;i<=(n-k+1);i++)
         solve(i , n , k , current , result);
        return result;
    }
};

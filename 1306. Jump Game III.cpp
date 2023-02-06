/*
Here , In this question 
   we use BFS
*/
class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        int n = arr.size();
        queue<int> qu;
        qu.push(start);
        unordered_set<int> st;
        // st.insert(start);

        while(!qu.empty()){
          int ind = qu.front();
          st.insert(ind);
          qu.pop();

          if(arr[ind]==0) return true;

          if((ind + arr[ind]<0) || (ind + arr[ind]>=n) || st.find(ind + arr[ind])!=st.end())
          {;}
          else
          qu.push(ind + arr[ind]);

         if((ind - arr[ind]<0) || (ind - arr[ind]>=n) || st.find(ind - arr[ind])!=st.end())
          {;}
          else
          qu.push(ind - arr[ind]);

        }
        return false;
    }
};

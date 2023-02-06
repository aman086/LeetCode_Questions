class Solution {
public:
    static bool cmp(pair<int,int> a , pair<int,int> b){
        return a.second<b.second;
    }
    int findLongestChain(vector<vector<int>>& pairs) {
         vector<pair<int,int>> vtr;
         for(auto it : pairs){
             vtr.push_back({it[0] , it[1]});
         }
         sort(vtr.begin() , vtr.end() , cmp);
         int i=1;
         int n = vtr.size();
         int second = vtr[0].second;
         int cnt = 1;
         while(i<n){
             while((i<n) && (second >= vtr[i].first))
                  i++;
              if(i==n) break;    
             if(second < vtr[i].first){
                 cnt++;
                 second = vtr[i].second;
                 i++;
             }
         }
         return cnt;
    }
};

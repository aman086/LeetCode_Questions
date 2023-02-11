/*
The single key point here is to remember that if any player is never been in second(loser) position in any match so we have to 
  add this to our map with count = 0;
  so that in zero loses matches player , we consider him
*/

class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        vector<vector<int>> resultArray;
        int n = matches.size();
        map<int,int> mp;
        for(int i=0;i<n;i++){
            vector<int> currentMatch = matches[i];
            int winner = currentMatch[0];
            int loser = currentMatch[1];
            if(mp.find(winner)==mp.end()) mp[winner]=0;
            mp[loser]++;
        }
        vector<int> notLostAnyMatch;
        vector<int> lostExactlyOneMatch;

        for(auto it : mp){
            // if(mp.find(it.first)==mp.end()) mp[it.first]=0;
            if(it.second==0)
              notLostAnyMatch.push_back(it.first);
            if(it.second==1)
              lostExactlyOneMatch.push_back(it.first);
        }
        // sort(notLostAnyMatch.begin() , notLostAnyMatch.end());
        // sort(lostExactlyOneMatch.begin() , lostExactlyOneMatch.end());
        resultArray.push_back(notLostAnyMatch);
        resultArray.push_back(lostExactlyOneMatch);
        return resultArray;
    }
};

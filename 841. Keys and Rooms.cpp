class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        unordered_set<int> key;
        queue<int> qu;
        int n = rooms.size();
        key.insert(0);
        for(auto vl : rooms[0]){
            if(key.find(vl)==key.end()){
                 key.insert(vl);
                 for(auto val : rooms[vl])
                    qu.push(val);
             } 
        }
         while(!qu.empty()){
             int currKey = qu.front();
             qu.pop();
             if(key.find(currKey)==key.end()){
                 key.insert(currKey);
                 for(auto vl : rooms[currKey])
                    qu.push(vl);
             } 
         }
        
         return key.size()==n; 
    }
};

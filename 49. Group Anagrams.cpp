class Solution {
public:

    vector<int> solve(int index , vector<string>& strs){
        vector<int> hsh(26 , 0);
        int n = strs[index].size();
        for(int i=0;i<n;i++)
            hsh[strs[index][i]-'a']++;
        return hsh;    
    }

    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> result;
        int cnt=0;
        int n = strs.size();
        map<vector<int> , int> mp;
        for(int i=0;i<n;i++){
            vector<int> ans = solve(i , strs);
            if(mp.find(ans)==mp.end()){
                mp[ans] = cnt;
                result.push_back({});
                result[cnt].push_back(strs[i]);
                cnt++;
            }else{
                int vl = mp[ans];
                result[vl].push_back(strs[i]);
            }
        }
        return result;
    }
};

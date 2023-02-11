class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> hsh_s(26 , 0);
        vector<int> hsh_t(26 , 0);
        if(s.size() != t.size()) return false;

        for(int i=0;i<s.size();i++){
            hsh_s[s[i]-'a']++;
            hsh_t[t[i]-'a']++;
        }
        return hsh_s == hsh_t;
        
    }
};

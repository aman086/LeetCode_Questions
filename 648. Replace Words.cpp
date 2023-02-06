class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        unordered_map<string , int> mp;
        for(auto it : dictionary){
            mp[it] = 1;
        }

        string finalAns = "";
        int n = sentence.size();
        string current = "";
        int i=0;
        while(i<n){
            if(sentence[i]==' '){
                finalAns += current;
                finalAns.push_back(' ');
                current = "";
                i++;
                continue;
            }

            current.push_back(sentence[i]);
            if(mp[current]>0){
                finalAns += current;
                finalAns.push_back(' ');
                while(i<n && sentence[i]!= ' '){
                    i++;
                }
                current = "";
                 
            }
            
            i++;
        }
        if(current.size()>0){
            finalAns += current;
            return finalAns;
        }
        finalAns.pop_back();
        return finalAns;
    }
};

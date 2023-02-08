class Solution {
public:
    int numSplits(string s) {
        int n = s.size();
        unordered_set<char> st;
        unordered_set<char> st1;
        vector<int> start(s.size());
        vector<int> end(s.size());
        start[0] = 1;
        st.insert(s[0]);
        end[n-1] = 1;
        st1.insert(s[n-1]);
        for(int i=1;i<n;i++){
            if(st.find(s[i])==st.end()){
               start[i] = start[i-1]+1;
               st.insert(s[i]);}
            else
              start[i] = start[i-1];   
        }
        for(int i=n-2;i>=0;i--){
            if(st1.find(s[i])==st1.end()){
               end[i] = end[i+1]+1;
               st1.insert(s[i]);}
             else
              end[i] = end[i+1];  
        }
        int cnt = 0;
        for(int i=0;i<n-1;i++){
            if(start[i]==end[i+1])
               cnt++;
        }
        return cnt;
    }
};

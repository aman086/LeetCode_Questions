class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        int n = s.size();
        if(s[n-1]=='1') return false;
        unordered_set<int> st;
        queue<int> qu;
        qu.push(0);
        st.insert(0);
        int end = 0;
        while(!qu.empty()){
            int size = qu.size();
            int index = qu.front();
            cout<<index<<" ";
            // st.insert(index);
            qu.pop();
            int start = max(index+minJump , end);
            if(start>(n-1)) return false;
             end = min(index + maxJump, n - 1);
            if(end==(n-1)) return true;
            for(int i=start;i<=end;i++){
                if(s[i]=='0' && (st.find(i)==st.end())){
                    st.insert(i);
                    qu.push(i);
                }
            }
            // size--;
            // // end++;
            // // start = end+1;
            // // end = min(index + maxJump, n - 1);
            // while(size>0){
            //     int curr = qu.front();
            //     start = end+1;
            //     if(start==n-1) return true;
            //     end = min(curr + maxJump, n - 1);
            //     if(end==(n-1)) return true;
            //     qu.pop();
            //     if(end==(n-1)) return true;
            //     for(int i=start;i<=end;i++){
            //     if(s[i]=='0' && (st.find(i)==st.end())){
            //         st.insert(i);
            //         qu.push(i);
            //     }
            //   }
            //     size--;
            // }
        }
        return false;
    }
};

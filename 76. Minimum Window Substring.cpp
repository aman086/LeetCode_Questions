/*
Here,
    we have to keeep remember some important points:
          s = "abcd"
          t = "d"
  then, the first window which is created = "abcd"
  so we have to minimize it firstly and store the length
  then 
    start traversing to remaining elements in S.
  and match values and increase count.
  if at any point , our starting index count is more than required, we apply a while loop
  till we match the count.

*/
class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.size();
        int m = t.size();
        unordered_map<char,int> hsh_t;
        unordered_map<char,int> hsh_s;
        for(int i=0;i<m;i++){
            hsh_t[t[i]]++;

        }
        int sz = hsh_t.size();
        cout<<hsh_t.size()<<endl;
        int start = 0;
        int index = -1;
        int cnt=0;
        for(int i=0;i<n;i++){
            hsh_s[s[i]]++;
            if(hsh_s[s[i]]==hsh_t[s[i]])
              cnt++;
            if(cnt==sz){
                index = i;
                break;
            }  
        }
        if(index==-1) return "";
        int str = 0;
        int end = index;
        
        while(start<=index && (hsh_s[s[start]]>hsh_t[s[start]]))
        {
            hsh_s[s[start]]--;
            start++;   
        }
        if((index-start+1)<(end-str+1)){
            str = start;
            end = index;
        }


        for(int i=index+1;i<n;i++){
            hsh_s[s[i]]++;
            
            while(start<=i && (hsh_s[s[start]]>hsh_t[s[start]]))
            {
                hsh_s[s[start]]--;
                start++;   
            }
            if((i-start+1)<(end-str+1)){
                str = start;
                end = i;
            }            
        }    
        return s.substr(str , (end-str+1));
    }
};

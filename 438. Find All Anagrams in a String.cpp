/*
It is same as 
        (76. Minimum Window Substring) && (567. Permutation in String)
      
*/
class Solution {
public:
    vector<int> findAnagrams(string p, string s) {
        unordered_map<char,int> hsh_s;
        unordered_map<char,int> hsh_p;
        int n1 = s.size();
        int n2 = p.size();
        for(int i=0;i<n1;i++)
            hsh_s[s[i]]++;
        int cnt=0;
        int sz = hsh_s.size();
        int index = -1;
         for(int i=0;i<n2;i++){
             hsh_p[p[i]]++;
             if(hsh_p[p[i]]==hsh_s[p[i]])
                cnt++;
              if(cnt == sz){
                  index = i;
                  break;
              }  
         }
         vector<int> result;
         if(index==-1) return result;
         int start = 0;
         int end = index;
        //  if((end-start+1) == n1)  result.push_back(start);
         while((start<=index) && (hsh_p[p[start]] > hsh_s[p[start]])){
             hsh_p[p[start]]--;
             start++;
         }
         if((end-start+1) == n1)  result.push_back(start);
         for(int i=index+1;i<n2;i++){
             hsh_p[p[i]]++;
             
             while((start<=i) && (hsh_p[p[start]] > hsh_s[p[start]])){
                    hsh_p[p[start]]--;
                    start++;
             }

             if((i-start+1) == n1) result.push_back(start);
         }
         return result;   
    }
};

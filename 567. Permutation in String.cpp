/*
Here , we have given two strings and we have to check whether any permutation of first string is a substring of second or not.
   So , we make a hsh_Array for first string and calculate count because  question is only concerend about count , that count of 
   every character in both string must be same , no matter they are in same order or not , order could be varry.
   and Reduce window of string second until we got a length is same as string first with the maintainning order of every character
   and if found then return true , otherwise return false;
*/
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<char,int> hsh_s1;
        unordered_map<char,int> hsh_s2;
        int n1 = s1.size();
        int n2 = s2.size();
        for(int i=0;i<n1;i++)
            hsh_s1[s1[i]]++;
        int cnt=0;
        int sz = hsh_s1.size();
        int index = -1;
         for(int i=0;i<n2;i++){
             hsh_s2[s2[i]]++;
             if(hsh_s2[s2[i]]==hsh_s1[s2[i]])
                cnt++;
              if(cnt == sz){
                  index = i;
                  break;
              }  
         }
         if(index==-1) return false;
         int start = 0;
         int end = index;
         if((end-start+1) == n1) return true;
         while((start<=index) && (hsh_s2[s2[start]] > hsh_s1[s2[start]])){
             hsh_s2[s2[start]]--;
             start++;
         }
         if((end-start+1) == n1) return true;
         for(int i=index+1;i<n2;i++){
             hsh_s2[s2[i]]++;
             
             while((start<=i) && (hsh_s2[s2[start]] > hsh_s1[s2[start]])){
                    hsh_s2[s2[start]]--;
                    start++;
             }

             if((i-start+1) == n1) return true;
         }
         return false;   
    }
};

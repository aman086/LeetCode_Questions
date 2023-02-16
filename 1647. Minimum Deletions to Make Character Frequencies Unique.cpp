/*
Here , 
Eg: "abbcccdddddeeeeeeffffffggggggghhhhhhhiiiiiiijjjjjjjjkkkkkkkk"
  we want an array who tells us that how many characters are their whose sum is this.
 like , count the no whose sum is 8 = 3;
    sum is 7 = 3;
    sum is 6 = 2;
    sum is 5 = 1;
    sum is 4 = 0;
    sum is 3 = 1;
    sum is 2 = 1;
    sum is 1 = 1;
    
    and simply start deleting from the last one.
     delete 2 elements frequency by 1 of count 8;
     then these 2 elements transferred into count 7 and increases count 7 by 2.
     similarly for 6 and from 6 to 5;
     until we reach to count 1;
     then at every point delete remaining extra count greater than 1 because at last , we have to make every element count 1;
     and finally add all of them
      
    

*/

class Solution {
public:
    int minDeletions(string s) {
        int n = s.size();
        unordered_map<char,int> mp;
        for(int i=0;i<n;i++)
            mp[s[i]]++;
        
        vector<int> prefix(100000 , 0);
        int maxi = 0;
        for(auto it : mp){
            prefix[it.second]++;
            maxi = max(maxi , it.second);
        }
        int sz = maxi;
        for(int i=sz-1;i>0;i--){
            if(prefix[i+1]!=0)
            prefix[i] += (prefix[i+1]-1);
        }  
 
        int sm=0;
        for(int i=0;i<=sz;i++){
            if(prefix[i]>1){
                sm+=(prefix[i]-1);
            }
        }  
        return sm;
    }
};

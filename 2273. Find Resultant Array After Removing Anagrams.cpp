/*
Here , 
   we are using two-pointer approach (start and end pointer)and maintaining a function for checking two strings,
        If they are equal then move the end pointer and stay the start pointer but if both are not equal then
        took value present at start index and do start = end and end++;(which increments already because of for loop)
           and at last after for loop , adding words[start] to it.
        
*/

class Solution {
public:

    bool compareTwoStrings(string first , string second){
        int n1 = first.size();
        int n2 = second.size();
        if(n1 != n2) return false;
        vector<int> hsh_first(26,0);
        vector<int> hsh_second(26,0);
        for(int i=0;i<first.size();i++){
            hsh_first[first[i]-'a']++;
            hsh_second[second[i]-'a']++;
        }
        return hsh_first == hsh_second;
    }
    vector<string> removeAnagrams(vector<string>& words) {
        int n = words.size();
        if(n==1) return words;
        vector<string> resultString;
        int start = 0;
        // words.push_back(" ");
        for(int end = 1;end < n;end++){
            
            if(!compareTwoStrings(words[start] , words[end])){
                    // Not equal
                    resultString.push_back(words[start]);
                    start = end;
            }
        }
        resultString.push_back(words[start]);
        return resultString;
    }
};

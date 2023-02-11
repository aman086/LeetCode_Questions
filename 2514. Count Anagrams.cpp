/*
Easy but some tricky portion is there , named as == Modulo Multiplicative Inverse
*/
class Solution {
public:
    long long int M = 1000000007;

    long long int reCalculate(long long int a , long long int b){
         long long int ans = 1;
         a = a%M;
         while(b>0){
             if(b&1){
                 ans = (ans*a)%M;
             }
             b>>=1 ;
             a = (a*a)%M;
         }
         return ans;
    }
    long long int inver(long long int a){
        return reCalculate(a , M-2);
    }
    long long int solve(string word , vector<long long int>& fact){
        int n = word.size();
        unordered_map<char,long long int> mp;
        for(int i=0;i<n;i++){
            mp[word[i]]++;
        }
        long long int result =  fact[n];
        for(int i=0;i<26;i++){
            if(mp[i+'a'] > 0)
            result = (result * inver(fact[mp[i+'a']]))%M;
        }
        return result;
    }


    int countAnagrams(string s) {
        int n = s.size();
        string word = s.substr(0,1);
        vector<long long int> fact(n+1 , 1);
        fact[0] = 1;
        for(int i=1;i<=n;i++){
            fact[i] = (i * fact[i-1])%M;
        }
        long long int countTotal = 1;
         for(int i=1; i<n; i++){
            if(s[i] == ' '){
                countTotal = (countTotal * solve(word, fact)) % M;
                word.clear();
            }
            else{
                word.push_back(s[i]);
            }
        }
        
        countTotal = (countTotal * solve(word, fact)) % M;
        return (int)countTotal;
    }
};

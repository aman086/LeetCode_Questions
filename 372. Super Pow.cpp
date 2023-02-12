/*
Observable things:
eg:
    a = 2, b = [4,3,3,8,5,2]
    means , we want (2)^(433852) = (2)^(400000+30000+3000+800+50+2)
      means it is equal to :- (2)^400000 * (2)^30000 * (2)^3000 * (2)^800 * (2)^50 * (2)^2;
              again it is , [{(2)^4}^100000] * [{(2)^3}^10000] * [{(2)^3}^1000] * [{(2)^8}^100] * [{(2)^5}^10] * [{(2)^2}^1]
                = [{(2)^4}^{(10)^5}] * [{(2)^3}^{(10)^4}] * [{(2)^3}^{(10)^3}] * [{(2)^8}^{(10)^2}] * [{(2)^5}^{(10)^1}] * [{(2)^2}^{(10)^0}]

*/

class Solution {
public:
     int M = 1337;
    int binPow(int a , int b){
        int ans = 1;
        while(b>0){
            if(b&1){
                ans = (ans * 1ll * a)%M;
            }
            a = (a *1ll * a)%M;
            b >>= 1;
        }
        return ans;
    }
    int superPow(int a, vector<int>& b) {
        int n = b.size();
        int result = 1;
        for(int i=n-1;i>=0;i--){
            int currVal = 1;
            currVal = binPow(a , b[i]);
            int pow = (n-1)-i;
            for(int j=0;j<pow;j++){
                currVal = binPow(currVal , 10);
            }
            result = (result *1ll * currVal)%M;
        }
        return result;
    }
};

/*
(1). Use Recursion
(2). everyTime divide by 2 and if no is odd then multiply that no to one more time otherwise no need
(3). if n<0 then solve the question for positive n and in last divide it by 1.
*/

class Solution {
public:
    double solve(double x , int n){
        if(n==0) return 1;
        double vl = solve(x , n/2);
        if(n&1){
            return (vl * vl * x);
        }else{
            return (vl * vl);
        }
    }
    double myPow(double x, int n) {
        if(n==0) return 1;
        if(n>0)
        return solve(x , n);
        // if(n<0)
        return 1/solve(x,n);
    }
};

/*
here , 
 we firstly make a prefixArr where prefixArr[i] = sum of all the elements from i to n;
 and again start traversing;
   and maintain a unordered_map to check the elment which we want to find is present or not and also the count of that element;
   then increase count and
 fn = target - current Element;
 then check is any subarray present means have we stored sum of such subarrays , which fullfil our requirement.
so we , check element with the prefix of that value because elments , where we are going to be searched they contain that extra prefixArr[i],
 so we search after plus the element.

*/


class Solution {
public:
     
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> prefixArr(n);
        prefixArr[n-1] = nums[n-1];
        for(int i=n-2;i>=0;i--){
            prefixArr[i] = prefixArr[i+1] + nums[i];
        }
        int cnt=0;
        unordered_map<int,int> st;
        for(int i=0;i<n;i++){
            st[prefixArr[i]]++;
            int fn = (k - nums[i]);
            if(st[fn + prefixArr[i]]!=0)
                cnt+=st[fn + prefixArr[i]];
        }
        return cnt;
    }
};

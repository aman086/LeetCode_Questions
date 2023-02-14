/*
Here , we have to think some differently that , 
    neighbour of any no can give average only if one neighbour is greater than element and another one is less than element.
    so I arrange array in such a way that , 
          neighbour of every element is either greater than currentElement or both neighbours are less than the element.
          
          Eg:
              [1,2,3,4,5,6]
              ans = [1,4,2,5,3,6]

*/

class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> finalAns(n);
        sort(nums.begin() , nums.end());
        int end = (n-1);
        int start = 0;
        int i = 0;
        while(start<=end){
            if(i&1) { finalAns[i] = nums[end]; end--;}
            else {finalAns[i] = nums[start]; start++;}
            i++;
        }
        // for(int i=0;i<n;i++){
        //     if(i&1){
        //         finalAns[i] = nums[k];
        //         k--;
        //     }else{
        //         finalAns[i] = nums[start];
        //         start++;
        //     }
        // }
        return finalAns;
    }
};

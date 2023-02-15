/*
Here , we do the simple things.
           if n = 5 and k=4;
           then combination is = [1,5,2,4,3]
            where differences = [4,3,2,1] which contains 4 distinct integer
            
            if k=3;
            then combination is = [1,5,2,3,4]
            where differences = [4,3,1,1] which contains 3 distinct integer
            
            if k=2;
            then combination is = [1,5,4,3,2]
            where differences = [4,1,1,1] which contains 2 distinct integer
            
            if k=1;
            then combination is = [1,2,3,4,5]
            where differences = [1,1,1,1] which contains 1 distinct integer
            
            We put elements alternatively, firstly smaller then bigger then smaller ang bigger and so on. until k==0
            if(k==0) means than we need only one distinct integer which is 1. so put all remaining elements at 1 distance.
            eg:
               if k=2;
               first choose minimum = 1; // k-- => k=1;
               choose maximum = 5; // k--m=> k=0;
               if(k==0)
                   then after 5 , I put elements ith difference 1 until I reached the first non-picked element.
                   
               if k=1;
               first choose minimum = 1; // k-- => k=0;
               if(k==0)
                    then after 1 , I put elements with difference 1 until I reached the last non-picked element.
*/

class Solution {
public:
    vector<int> constructArray(int n, int k) {
        vector<int> finalAns;
        int start = 1;
        int end = n;
        int ind =0;
        while(ind<n && start<end){
            if(ind&1)
            finalAns.push_back(end--); 
            else
            finalAns.push_back(start++);
            k--;
            if(k==0){
                break;
            }
            ind++;
        }
        
        if(ind&1){
            ind++;
            for(int i=end;i>=start;i--)
              finalAns.push_back(i);
        }else{
            for(int i=start;i<=end;i++)
              finalAns.push_back(i);
        }

        return finalAns;
    }
};

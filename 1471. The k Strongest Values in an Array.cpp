class Solution {
public:
    vector<int> getStrongest(vector<int>& arr, int k) {
        vector<int> check(arr.begin() , arr.end());
        sort(check.begin() , check.end());
        int n = arr.size();
        int median = check[((n-1)/2)];
        vector<pair<int,int>> vtr;
        for(int i=0;i<n;i++){
            vtr.push_back({median-arr[i] , arr[i]});
        }
        sort(vtr.begin() , vtr.end());
        vector<int> final;
        int start = 0;
        int end = n-1;
        while(k--){
            if(abs(vtr[start].first) > abs(vtr[end].first)){
                final.push_back(vtr[start].second);
                start++;
            }else if(abs(vtr[start].first) < abs(vtr[end].first)){
                final.push_back(vtr[end].second);
                end--;
            }else{
                 if(vtr[start].second > vtr[end].second){
                     final.push_back(vtr[start].second);
                     start++;
                 }else{
                     final.push_back(vtr[end].second);
                     end--;
                 }
            }
            // k--;
        }
        return final;
    }
};

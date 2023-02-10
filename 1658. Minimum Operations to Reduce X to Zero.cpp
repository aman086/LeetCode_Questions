class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size();
        long int sum = 0;
        unordered_map<int,int> mp;
        mp[0] = 0;
        int mini = INT_MAX;
        // cout<<n<<endl;
        int sm = 0;
        for(int i=0;i<n;i++){
            sm += nums[i];
            if(sm>x) break;
            if(sm==x) mini = min(mini , i+1);
            mp[sm] = (i+1);
        }
        sm =0;
        for(int i=n-1;i>=0;i--){
            sm += nums[i];
            if(sm > x) break;
            if(mp.find(x-sm)!=mp.end()){
                if((n-i)+mp[x-sm] > n) continue;
                mini = min(mini , (n-i)+mp[x-sm]);
            }
            // if(mp.find(sm) != mp.end()){
            //     mp[sm] = (n - i);
            // }    
            
        }
        if(mini == INT_MAX) return -1;
        return mini;
    }
};

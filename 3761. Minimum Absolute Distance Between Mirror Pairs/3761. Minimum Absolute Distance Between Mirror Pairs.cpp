lass Solution {
    int rev(int n){
        int rev = 0;
        while(n!=0){
            rev*=10;
            rev+= n%10;
            n/=10;
        }
        return rev;
    }
public:
    int minMirrorPairDistance(vector<int>& nums) {
        int n = nums.size();
        int ans = n;
        unordered_map<int,int>mp;
        for(int i=0; i<n; i++){
            int check = rev(nums[i]);
            if(mp.find(nums[i])!=mp.end()){
                ans = min(ans,abs(i-mp[nums[i]]));
            }
            mp[check] = i;
        }
        if(ans==n){
            return -1;
        }
        return ans;
    }
};
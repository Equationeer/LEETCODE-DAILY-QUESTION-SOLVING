class Solution {
public:
    int mirrorDistance(int n) {
        return abs(n - find(n));
    }
    private:
    int find(int n){
        int ans =0 ;
        while(n){
            int rem = n%10;
            ans = ans*10+rem;
            n/=10;
        }
        return ans;
    }
};
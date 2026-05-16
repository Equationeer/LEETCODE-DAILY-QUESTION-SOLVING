class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums[0];

        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] < n) {
                n = nums[i];
            }
        }
        return n;
       
    }
};
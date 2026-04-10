class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        unordered_map<int, vector<int>> pos;
        
        for (int i = 0; i < nums.size(); i++) {
            pos[nums[i]].push_back(i);
        }
        
        int ans = INT_MAX;
        
        for (auto& entry : pos) {
            vector<int>& indices = entry.second;
            
            if (indices.size() < 3) 
            continue;
            
            for (int i = 0; i + 2 < indices.size(); i++) {
                int distance = 2 * (indices[i + 2] - indices[i]);
                ans = min(ans, distance);
            }
        }
        
       if(ans == INT_MAX) 
       return -1;
       return ans;
    }
};
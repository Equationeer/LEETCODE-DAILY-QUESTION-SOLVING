class Solution {
public:
    vector<int> findDegrees(vector<vector<int>>& matrix) {
        int n=matrix.size();
        vector <int> ans(n,0);
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<matrix.size(); j++)
            {
                ans[i]+=matrix[j][i];
            }
        }
        return ans;
    }
};
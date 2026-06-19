class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int alt = 0, mx=0;
        for(int i=0;i<gain.size();i++){
            alt+=gain[i];
            mx = max(mx,alt);
        }
        return mx;
    }
};
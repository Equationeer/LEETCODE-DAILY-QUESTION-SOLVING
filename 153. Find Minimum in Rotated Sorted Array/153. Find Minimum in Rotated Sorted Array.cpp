class Solution {
public:
    int findMin(vector<int>& arr) {
        int start = 0, end = arr.size()-1, ans = arr[0];
        while(start<=end)
        {
            int mid = start+(end-start)/2;

            // left side sorted 
            if(arr[mid]>=arr[0])
            start=mid+1;

            // right side sorted
            else
            {
                ans = arr[mid];
                end = mid-1;
            }
        }
        return ans;
    }
};
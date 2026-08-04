class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        vector<int> ans;
        map<int, int> mpp;
        int maxi = INT_MIN;
        int mini = INT_MAX;
        for (int t : nums) {
            mpp[t]++;
            maxi = max(maxi, t);
            mini = min(mini, t);
        }
        for (int i = mini; i <= maxi; i++) {
            if (mpp[i] == 0)
                ans.push_back(i);
        }
        return ans;
    }
};
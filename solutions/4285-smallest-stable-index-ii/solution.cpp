class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {

        vector<int> prefixMax;
        int maxi = INT_MIN;

        for (auto i:nums) {
            if (i > maxi) {
                maxi = i;
            }
            prefixMax.push_back(maxi);
        }

        vector<int> suffixMin;
        int mini = INT_MAX;

        for (auto it = nums.rbegin(); it != nums.rend(); ++it) {
            if (*it < mini) {
                mini = *it;
            }
            suffixMin.push_back(mini);
        }

        reverse(suffixMin.begin(), suffixMin.end());

        for (int i = 0; i < nums.size(); i++) {
            if (prefixMax[i] - suffixMin[i] <= k) {
                return i;
            }
        }
        return -1;
    }
};

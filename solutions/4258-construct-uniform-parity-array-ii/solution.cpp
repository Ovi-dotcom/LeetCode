class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        bool odd = false;
        bool even = false;
        for (auto i:nums1) {
            if (i % 2 == 0) {
                continue;
            } else {
                odd = true;
            }
        }
        if (!odd) return true;
        for (auto i:nums1) {
            if (i % 2 == 1) {
                continue;
            } else {
                even = true;
            }
        }
        if (!even) return true;

        int smallest = INT_MAX;
        for (auto i:nums1) {
            if (i < smallest) {
                smallest = i;
            }
        }
        if (smallest % 2 == 0) {
            return false;
        }
        return true;
    }
};

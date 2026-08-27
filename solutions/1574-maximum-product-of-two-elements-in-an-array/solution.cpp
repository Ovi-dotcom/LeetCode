class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxi = INT_MIN, secmaxi = INT_MIN;

        for (int num : nums) {
            if (num >= maxi) {
                secmaxi = maxi;
                maxi = num;
            }
            else if (num > secmaxi) {
                secmaxi = num;
            }
        }

        return (maxi - 1) * (secmaxi - 1);
    }
};

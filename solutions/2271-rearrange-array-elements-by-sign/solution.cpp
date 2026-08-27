class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> positive;
        vector<int> negative;
        for (int i : nums) {
            if (i < 0)
                negative.push_back(i);
            else
                positive.push_back(i);
        }
        vector<int> result;
        int i = 0;
        while (i < positive.size()) {
            result.push_back(positive[i]);
            result.push_back(negative[i]);
            i++;
        }
        return result;
    }
};

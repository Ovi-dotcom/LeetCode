class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> result;
        vector<int>:: iterator it1;
        vector<int>:: iterator it2;
        for(it1 = nums.begin(); it1 != nums.end(); ++it1){
            it2 = find(it1+1,nums.end(), target - *it1);
            if(it2 != nums.end()){
                result.push_back(it1 - nums.begin());
                result.push_back(it2 - nums.begin());
                break;
            }
        }
        return result;
    }
};

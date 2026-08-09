class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> fr;
        vector<int> res;
        for(const auto &i:nums){
            fr[i]++;
        }
        vector<pair<int,int>> arr;
        for(const auto &pair:fr){
            arr.push_back({pair.second, pair.first});
        }
        sort(arr.rbegin(), arr.rend());
        for(int i=0;i<k;i++){
            res.push_back(arr[i].second);
        }
        return res;
    }
};

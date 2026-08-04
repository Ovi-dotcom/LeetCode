class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int,int> fr;
        for(auto i:nums){
            fr[i]++;
        }
        int maxfr = 0;
        int totalfr = 0;
        for(const auto& pair : fr){
            if(pair.second > maxfr){
                maxfr = pair.second;
            }            
        }
        for(const auto& pair : fr){
            if(pair.second == maxfr) totalfr += maxfr;
        }
        return totalfr;
    }
};

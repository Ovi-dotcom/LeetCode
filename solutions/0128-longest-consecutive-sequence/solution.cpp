class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> look;
        if(nums.size()==0) return 0;
        int len;
        int maxi=INT_MIN;
        for(int &i:nums){
            look.insert(i);
        }
        for(int i:look){

            if(look.find(i-1) != look.end()) continue;

            len = 1;
            int curr=i;

            while(look.find(curr+1) != look.end()){
                curr++;
                len++;
            }
            maxi = max(len,maxi);
            
        }
        return maxi;
    }
};

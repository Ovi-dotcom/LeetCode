class Solution {
public:
    int findMin(vector<int>& nums) {
        int l=0, r=nums.size()-1;
        int mini = INT_MAX;
        while(l<=r){
            if(nums[l] < mini) mini = nums[l];
            if(nums[r] < mini) mini = nums[r];
            l++;
            r--;
        }
        return mini;
    }
};

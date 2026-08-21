class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() > nums2.size()) {
            return findMedianSortedArrays(nums2, nums1);
        }
        
        int total = nums1.size() + nums2.size();
        int half = total / 2; 
        
        int l = 0;
        int r = nums1.size(); 
        
        while (l <= r) {
            
            int i = l + (r - l) / 2; 
            int j = half - i;
            
            int Aleft  = (i == 0) ? INT_MIN : nums1[i - 1];
            int Aright = (i == nums1.size()) ? INT_MAX : nums1[i];
            
            int Bleft  = (j == 0) ? INT_MIN : nums2[j - 1];
            int Bright = (j == nums2.size()) ? INT_MAX : nums2[j];
            
            if (Aleft <= Bright && Bleft <= Aright) {
                if (total % 2 != 0) {
                    return (double)min(Aright, Bright);
                } else {
                    int leftMax = max(Aleft, Bleft);
                    int rightMin = min(Aright, Bright);
                    return (leftMax + rightMin) / 2.0;
                }
            } else if (Aleft > Bright) {
                r = i - 1;
            } else {
                l = i + 1;
            }
        }
        
        return 0.0;
    }
};

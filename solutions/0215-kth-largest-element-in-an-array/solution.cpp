class Solution {
public:
    // 3-way partition: handles duplicates in O(n) instead of O(n²)
    // Returns {left_boundary, right_boundary} of pivot region
    pair<int,int> partition3(vector<int>& nums, int left, int right) {
        // Random pivot to avoid sorted/near-sorted worst case
        int randIdx = left + rand() % (right - left + 1);
        swap(nums[randIdx], nums[right]);

        int pivot = nums[right];
        int lt = left;   // nums[left..lt-1]  > pivot
        int gt = right;  // nums[gt+1..right] < pivot
        int i  = left;

        while (i <= gt) {
            if (nums[i] > pivot)
                swap(nums[lt++], nums[i++]);
            else if (nums[i] < pivot)
                swap(nums[i], nums[gt--]);
            else
                i++;
        }
        return {lt, gt};
    }

    int quickSelect(vector<int>& nums, int left, int right, int k) {
        if (left == right) return nums[left];

        auto [lt, gt] = partition3(nums, left, right);

        // k is 1-indexed; lt/gt are 0-indexed positions
        if (k - 1 < lt)       return quickSelect(nums, left,  lt - 1, k);
        else if (k - 1 > gt)  return quickSelect(nums, gt + 1, right, k);
        else                  return nums[lt];
    }

    int findKthLargest(vector<int>& nums, int k) {
        srand(time(0));
        return quickSelect(nums, 0, nums.size() - 1, k);
    }
};

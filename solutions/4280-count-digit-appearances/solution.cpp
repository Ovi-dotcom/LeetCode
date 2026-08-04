class Solution {
public:
    int countDigitOccurrences(vector<int>& nums, int digit) {
        int count = 0;
        for(auto a: nums){
            while(a>0){
                if(a%10 == digit) count++;
                a /= 10;
            }
        }
        return count;
    }
};

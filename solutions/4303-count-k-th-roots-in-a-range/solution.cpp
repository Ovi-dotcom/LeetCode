class Solution {
public:
    long long power(long long a, int k, long long limit) {
        long long res = 1;

        while (k--) {
            if (a != 0 && res > limit / a) {
                return limit + 1;
            }

            res *= a;
        }

        return res;
    }

    int countKthRoots(int l, int r, int k) {

        long long low = 0;
        long long high = 1000000000;

        while (low < high) {
            long long mid = (low + high) / 2;

            if (power(mid, k, r) >= l) {
                high = mid;
            } else {
                low = mid + 1;
            }
        }

        long long start = low;

        low = 0;
        high = 1000000000;

        while (low < high) {
            long long mid = (low + high + 1) / 2;

            if (power(mid, k, r) <= r) {
                low = mid;
            } else {
                high = mid - 1;
            }
        }

        long long end = low;

        if (start > end) {
            return 0;
        }

        return end - start + 1;
    }
};

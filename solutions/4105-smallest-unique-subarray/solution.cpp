class Solution {
public:
    using ull = unsigned long long;

    int smallestUniqueSubarray(vector<int>& nums) {
        int n = nums.size();

        vector<ull> pref(n + 1, 0);
        vector<ull> power(n + 1, 1);

        ull base = 911382323;

        for (int i = 0; i < n; i++) {
            pref[i + 1] = pref[i] * base + (ull)(nums[i] + 1000007);
            power[i + 1] = power[i] * base;
        }

        auto getHash = [&](int l, int r) {
            return pref[r + 1] - pref[l] * power[r - l + 1];
        };

        auto check = [&](int len) {
            unordered_map<ull, int> freq;

            for (int i = 0; i + len - 1 < n; i++) {
                ull h = getHash(i, i + len - 1);
                freq[h]++;
            }

            for (auto &p : freq) {
                if (p.second == 1) {
                    return true;
                }
            }

            return false;
        };

        int left = 1;
        int right = n;
        int ans = n;

        while (left <= right) {
            int mid = (left + right) / 2;

            if (check(mid)) {
                ans = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        return ans;
    }
};

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.length() > s2.length()) return false;

        int need[26] = {};
        int window[26] = {};

        for (char ch : s1) {
            need[ch - 'a']++;
        }

        int len = s1.length();

        for (int i = 0; i < len; i++) {
            window[s2[i] - 'a']++;
        }

        if (memcmp(need, window, sizeof(need)) == 0) {
            return true;
        }

        for (int right = len; right < s2.length(); right++) {
            
            window[s2[right] - 'a']++;

            window[s2[right - len] - 'a']--;

            if (memcmp(need, window, sizeof(need)) == 0) {
                return true;
            }
        }

        return false;
    }
};

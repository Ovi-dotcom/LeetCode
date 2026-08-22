class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char, int> str;
        for (char ch : s) {
            str[ch]++;
        }
        int i = 0;
        for (char ch : s) {
            if (str[ch] == 1) {
                return i;
            }
            i++;
        }
        return -1;
    }
};

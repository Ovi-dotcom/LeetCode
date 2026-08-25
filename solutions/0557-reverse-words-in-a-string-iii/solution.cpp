class Solution {
public:
    string reverseWords(string s) {
        int i = 0, j = 0;
        while (j < s.length()) {
            while (j < s.length() && s[j] != ' ') {
                j++;
                continue;
            }
            string str = s.substr(i, j - i);
            reverse(str.begin(), str.end());
            for (char ch:str) {
                s[i++] = ch;
            }
            i = j + 1;
            j++;
        }
        return s;
    }
};

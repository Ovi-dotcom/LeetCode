class Solution {
public:
    bool isSubsequence(string s, string t) {
        if (s.length() > t.length())
            return false;
        if (s.empty())
            return true;
        int i = 0;
        int j = 0;
        while (j < t.length()) {
            if (s[i] == t[j]) {
                i++;
                if (i == s.length())
                    return true;
            }
            j++;
        }
        return false;
    }
};

class Solution {
public:
    bool validPalindrome(string s) {

        int l = 0;
        int r = s.length() - 1;
        while (l < r) {
            if (s[l] == s[r]) {
                l++;
                r--;
                continue;
            } else {
                if(checkPalindrome(s, l + 1, r)){
                    return true;
                }
                if(checkPalindrome(s, l, r - 1)){
                    return true;
                }
                return false;
            }
        }
        return true;
    }

    bool checkPalindrome(string& s, int l, int r) {
        while (l < r) {
            if(s[l]  == s[r]) {
                l++;
                r--;
                continue;
            } else {
                return false;
            }
        }
        return true;
    }
};

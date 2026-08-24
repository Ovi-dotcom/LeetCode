class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string res = "";
        int sStrLen = INT_MAX;
        int minIndex;
        int i = 0;
        for (string str : strs) {
            if (str.length() < sStrLen) {
                sStrLen = str.length();
                minIndex = i;
            }
            i++;
        }
        for (int j = 0; j < strs[minIndex].length(); j++) {
            for (int k = 0; k < strs.size(); k++) {
                if (strs[k][j] != strs[minIndex][j]) {
                    return strs[minIndex].substr(0, j);
                }
            }
        }
        return strs[minIndex];
    }
};

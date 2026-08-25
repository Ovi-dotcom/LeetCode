class Solution {
public:
    int compress(vector<char>& chars) {
        int index = 0;
        int i = 0, j = 0;
        while (j < chars.size()) {
            int count = 0;
            while (j < chars.size() && chars[i] == chars[j]) {
                count++;
                j++;
            }
            if (count == 1) {
                chars[index++] = chars[i];
            } else {
                chars[index++] = chars[i];
                string num = to_string(count);
                for (char ch:num) {
                    chars[index++] = ch;
                }
            }
            i = j;
        }
        return index;
    }
};

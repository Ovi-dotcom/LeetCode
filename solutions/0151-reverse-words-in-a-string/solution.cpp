class Solution {
public:
    string reverseWords(string s) {
        stringstream ss(s);
        string word;
        vector<string> words;
        while (ss >> word) {
            words.push_back(word);
        }
        string res;
        reverse(words.begin(), words.end());
        for (string str:words) {
            if (!res.empty()) res += ' ';
            res += str;
        }
        return res;
    }
};

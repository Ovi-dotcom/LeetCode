class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        if(s.length() < p.length()) return {};
        vector<int> res;

        int ch1[26] = {0};
        int ch2[26] = {0};

        for (char ch : p) {
            ch1[ch - 'a']++;
        }

        int len = p.length();
        
        for (int i = 0; i < len; i++) {
            ch2[s[i] - 'a']++;
        }

        bool match = true;
        for (int i = 0; i < 26; i++) {
            if (ch1[i] != ch2[i]) {
                match = false;
                break;
            }
        }

        if (match) res.push_back(0);

        for (int r = len; r < s.length(); r++) {
            ch2[s[r] - 'a']++;
            ch2[s[r - len] - 'a']--;

            bool match = true;
            for (int i = 0; i < 26; i++) {
                if (ch1[i] != ch2[i]) {
                    match = false;
                    break;
                }
            }

            if (match) res.push_back(r - len + 1);
        }

        return res;
    }
};

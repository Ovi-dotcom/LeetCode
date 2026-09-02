class Solution {
public:
    int romanToInt(string s) {
        int res = 0;
        unordered_map<char,int> lookup;
        lookup['I'] = 1;
        lookup['V'] = 5;
        lookup['X'] = 10;
        lookup['L'] = 50;
        lookup['C'] = 100;
        lookup['D'] = 500;
        lookup['M'] = 1000;
        
        for (int i = s.length() - 1; i >= 0; i--) {
            res += lookup[s[i]];
            if (i - 1 >= 0 && lookup[s[i - 1]] < lookup[s[i]]) {
                res -= lookup[s[i - 1]];
                i--;
                continue;                
            }
        
        }
        return res;
    }
};

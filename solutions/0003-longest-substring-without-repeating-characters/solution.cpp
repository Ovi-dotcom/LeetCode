class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> look;

        int l=0, maxi=0;

        for(int r=0;r<s.length();r++){

            while(look.contains(s[r])){
                look.erase(s[l]);
                l++;
            }

            look.insert(s[r]);
            int len =  r - l +1;
            maxi = max(len,maxi);
        }
        return maxi;
    }
};

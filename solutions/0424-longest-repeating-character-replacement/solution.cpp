class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char,int> hashMap;
        int l=0, maxi=0, maxFr=0;

        for(int r=0;r<s.length();r++){

            hashMap[s[r]]++;
            maxFr = max(maxFr,hashMap[s[r]]);

            while((r - l + 1) - maxFr > k){
                hashMap[s[l]]--;
                l++;
            }

            maxi = max(maxi, r - l + 1);
        }

        return maxi;
    }
};

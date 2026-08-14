class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int> hashMap;
        for(const char &ch:t){
            hashMap[ch]++;
        }

        int l=0,mini=INT_MAX,have=0,need=hashMap.size(),start=0;

        unordered_map<char,int> lookup;
        for(int r=0;r<s.length();r++){
            lookup[s[r]]++;

            if(hashMap.count(s[r]) && lookup[s[r]] == hashMap[s[r]]){
                have++;
            }

            while(have == need){
                if(r - l + 1 < mini){
                    mini = r - l + 1;
                    start = l;
                }
                lookup[s[l]]--;
                if(hashMap.count(s[l]) && lookup[s[l]] < hashMap[s[l]]){
                    have--;
                }
                
                l++;
            }
        }
        if(mini==INT_MAX) return "";
        return s.substr(start,mini);
    }
};

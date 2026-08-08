class Solution {
public:
    bool isAnagram(string s, string t) {
        int sn=s.length();
        int tn=t.length();
        if(sn!=tn) return false;
        unordered_map<char,int> sf;
        unordered_map<char,int> tf;
        for(auto &ch:s){
            sf[ch]++;
        }
        for(auto &ch:t){
            tf[ch]++;
        }
        for(int i=0;i<sn;i++){
        if(sf[s[i]] != tf[s[i]]) return false;
        }
        return true;

    }
};

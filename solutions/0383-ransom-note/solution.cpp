class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int noteLen = ransomNote.length();
        int magLen = magazine.length();
        if(noteLen > magLen) {
            return false;
        }
        unordered_map<char,int> noteFr;
        unordered_map<char,int> magFr;
        for(char ch:ransomNote) noteFr[ch]++;
        for(char ch:magazine) magFr[ch]++;
        for(char ch:ransomNote) {
            if(noteFr[ch] <= magFr[ch]) {
                continue;
            } else {
                return false;
            }
        }
        return true;
    }
};

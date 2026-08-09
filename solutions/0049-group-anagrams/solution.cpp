class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        unordered_map<string,vector<string>> hash;
        for(int i=0;i<strs.size();i++){
            int count[26]={0};
            for(int j=0;j<strs[i].length();j++){
                count[strs[i][j] - 'a']++;
            }
            string key="";
            for(int k=0;k<26;k++){
                key += to_string(count[k]) + ',';
            }
            hash[key].push_back(strs[i]);
        }

        for(const auto &pair:hash){
            res.push_back(pair.second);
        }
        return res;
    }
};

class Solution {
public:
    int numDifferentIntegers(string word) {
        unordered_set<string> unique_nums;
        int n=word.size();
        int i =0;
        while(i<n){
            
            if(isdigit(word[i])){
                int j =i;
                while(j<n && isdigit(word[j])){
                    j++;
                }
                while(i<j && word[i]=='0'){
                    i++;
                }
                if(i==j){
                    unique_nums.insert("0");
                } else {
                    unique_nums.insert(word.substr(i,j-i));
                }
                i=j;
            } else {
                i++;
            }
        }
        return unique_nums.size();
    }
};

class Solution {
public:
    bool isValid(string s) {
        int len = s.length();
        if(len%2 == 1) return false;
        unordered_map<char,char> hMap;
        hMap['('] = ')';
        hMap['{'] = '}';
        hMap['['] = ']';
        stack<char> st;
        for(int i=0;i<len;i++){
            if(!st.empty() && s[i] == hMap[st.top()]){
                st.pop();
                continue;
            }
            st.push(s[i]);
        }
        return st.empty();        
    }
};

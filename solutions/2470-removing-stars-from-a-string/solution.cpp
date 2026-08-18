class Solution {
public:
    string removeStars(string s) {
        string res = "";
        stack<char> st;
        for(char ch: s){
            if(st.empty() && ch == '*'){
                continue;
            } else if (!st.empty() && ch == '*'){
                st.pop();
            } else {
                st.push(ch);
            }
        }
        while(!st.empty()){
            res += st.top();
            st.pop();
        }
        reverse(res.begin(),res.end());
        return res;
    }
};

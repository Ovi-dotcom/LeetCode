class Solution {
public:
    int minOperations(vector<string>& logs) {
        int step = 0;
        stack<string> st;
        for(string strr: logs){
            if(strr == "../"){
                if(!st.empty()){
                    st.pop();
                }
            } else if(strr == "./"){
                continue;
            } else {
                st.push(strr);
            }            
        }
        while(!st.empty()){
            st.pop();
            step++;
        }
        return step;
    }
};

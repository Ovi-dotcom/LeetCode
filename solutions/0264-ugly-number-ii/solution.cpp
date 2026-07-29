class Solution {
public:
    int nthUglyNumber(int n) {
        set<long> st;
        long currUgly = 1;
        st.insert(currUgly);
        for(int i=1; i<=n; i++){
            currUgly = *st.begin();
            st.erase(*st.begin());

            st.insert(currUgly*2);
            st.insert(currUgly*3);
            st.insert(currUgly*5);
        }
        return (int) currUgly;
    }
};
